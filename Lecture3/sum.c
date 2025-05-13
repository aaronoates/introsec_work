#include <sys/stat.h>

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>

// Add up some integers in a (binary) file.
long sum_integers(const char *filename);


int
main(int argc, char *argv[])
{
	if (argc < 2)
	{
		err(EX_USAGE, "Usage:  sum <filename>");
	}

	const char *filename = argv[1];

	printf("Calling sum_integers()...\n");
	long sum = sum_integers(filename);

	printf("Sum is %ld\n", sum);

	return 0;
}


long
sum_integers(const char *filename)
{
	int data[8];
	int n;
	long sum = 0;

	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		err(-1, "Failed to open '%s'", filename);
	}

	printf("Reading size...");
	int bytes = fread(&n, sizeof(n), 1, f);
	if (bytes != 1)
	{
		err(-1, "Error reading size from '%s'", filename);
	}

	printf("Loading %u numbers into array at %p...\n", n, data);
	bytes = fread(data, sizeof(int), n, f);
	if (bytes < 0)
	{
		err(-1, "Error reading from '%s'", filename);
	}

	printf("Calculating sum of %d integers:\n", bytes);
	for (int i = 0; i < bytes; i++)
	{
		printf("%3d:  0x%02x\n", i, data[i]);
		sum += data[i];
	}

	printf("\nDone.\n");

	return sum;
}