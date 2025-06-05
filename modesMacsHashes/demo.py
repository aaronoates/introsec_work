#!/usr/bin/env python3

import base64
import click
import hashlib
import hmac
import random


def readable(raw_bytes):
    """Show bytes in a more readable format."""

    return base64.b64encode(raw_bytes).decode("utf-8")




@click.command()
@click.argument('message', nargs=-1)
@click.option('--use-hmac', is_flag=True)
def hash_or_hmac(message, use_hmac):
    if use_hmac:
        print("HMAC demo:\n")
        key = random.randbytes(16)

        hash_fn = lambda msg: hmac.digest(key, msg, 'sha256')
        attacker_hash_fn = lambda msg: hmac.digest(b'00000000', msg, 'sha256')

    else:
        print("Hash-based demo:\n")

        hash_fn = lambda msg: hashlib.sha256(msg).digest()
        attacker_hash_fn = lambda msg: hashlib.sha256(msg).digest()

    run_demo(message, hash_fn, attacker_hash_fn)


def run_demo(message, hash_fn, attacker_hash_fn):
    # A legitimate sender sends a message
    message = ' '.join(message).encode('utf-8')
    print(f"Message:    {message}")
    print(f"            {message.hex()}")
    print(f"            {readable(message)}")

    h = hash_fn(message)
    print(f"Hash:       {readable(h)}")

    sent = message + h
    print(f"Sent:       {readable(sent)}")

    # Mwa ha ha ha, an attacker intercepts the message!
    print("\n... dum dum DAH! ...\n")
    intercepted_message, intercepted_hash = sent[:-32], sent[-32:]

    evil_message = intercepted_message + b"... not!"
    print(f"New mssage: {evil_message}")

    evil_hash = attacker_hash_fn(evil_message)
    print(f"New hash:   {readable(evil_hash)}")

    resent = evil_message + evil_hash
    print(f"Resent:     {readable(resent)}")

    # The unsuspecting recipient receives the mutated message
    print("\nReceived...\n")

    message, h = resent[:-32], resent[-32:]
    print(f"Message:    {message}")
    print(f"Hash:       {readable(h)}")

    my_hash = hash_fn(message)
    print(f"My hash:    {readable(my_hash)}")

    print()

    if h == my_hash:
        print("Checks out... message is authentic.")
    else:
        print("Not authentic.")


if __name__ == "__main__":
    hash_or_hmac()