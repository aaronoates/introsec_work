#include <sys/stat.h>

#include <err.h>
#include <stdio.h>
#include <string.h>

// How large is a particular file (in bytes)?
unsigned int get_file_size(const char *filename);

// Load some integers from a (binary) file.
void load_integers(const char *filename);


int
main(int argc, char *argv[])
{
	printf("Calling load_integers()...\n");

	// Accept filename from user but default to stuff.dat
	const char *filename = (argc > 1) ? argv[1] : "stuff.dat";
	load_integers(filename);

	printf("Back in main!\n");

	return 0;
}


void
load_integers(const char *filename)
{
	int data[8];

	unsigned int file_size = get_file_size(filename);

	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		err(-1, "Failed to open '%s'", filename); // %s means string, so this just means failed to open string.
	}

        printf("Loading %u B into array at %p...\n", file_size, data); //Loading an unsigned int 

	int bytes = fread(data, sizeof(int), file_size / sizeof(int), f);
	if (bytes < 0)
	{
		err(-1, "Error reading from '%s'", filename);
	}

	printf("Read %d integers:", bytes);
	for (int i = 0; i < bytes; i++)
	{
		printf(" %d", data[i]);
	}
	printf("\n");
}


unsigned int
get_file_size(const char *filename)
{
	struct stat sb;
	if (stat(filename, &sb) < 0)
	{
		err(-1, "Failed to stat() '%s'", filename);
	}

	return sb.st_size;
}