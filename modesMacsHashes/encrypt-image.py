#!/usr/bin/env python3

import click
import os

from Crypto.Cipher import AES
from PIL import Image


@click.command()
@click.argument('input_image', type=click.File('rb'))
@click.argument('output_image', type=click.File('wb'))
@click.option('-k', '--key', default="ECE7420/ENGI9823")
@click.option('-m', '--mode', default='ECB')
def demo(input_image, output_image, key, mode):
    mode = mode.upper()
    if mode not in ('CBC', 'ECB'):
        raise click.UsageError(f"Invalid mode: {mode}")

    _, ext = os.path.splitext(output_image.name)

    image = Image.open(input_image).convert('RGB')
    encrypted = encrypt(image, key.encode("UTF-8"), mode)
    encrypted.save(output_image, ext[1:])


def encrypt(image, key, mode):
    """Encrypt a PIL image with AES using the specified key
    and block cipher mode."""

    # Convert image buffer to raw bytes and pad to block size
    plaintext = pad(image.tobytes(), 16)

    if mode == 'CBC':
        iv = os.urandom(16)
        aes = AES.new(key, AES.MODE_CBC, iv)

    elif mode == 'ECB':
        aes = AES.new(key, AES.MODE_ECB)

    # Encrypt!
    ciphertext = aes.encrypt(plaintext)

    # create an image from the encrypted string
    return Image.frombytes(image.mode,
                           image.size,
                           ciphertext,
                           'raw')

def pad(data, block_size):
    """Pad data to fit in an integer number of blocks."""
    return data + (block_size - len(data) % block_size) * b"."


if __name__ == "__main__":
    demo()