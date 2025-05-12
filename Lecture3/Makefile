CFLAGS=	-g -z execstack

all: sh sum

clean:
	rm -f *.core sh sum

sh: sh.s
	nasm sh.s -o sh

sum: sum.c
	$(CC) $(CFLAGS) sum.c -o sum
