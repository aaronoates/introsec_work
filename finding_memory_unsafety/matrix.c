#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	load_matrix(const char *filename, size_t *width, size_t *height, int);
double	compute(double *matrix, size_t width, size_t height);


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage:  vulnerable MATRIX_FILE\n");
		exit(1);
	}

	for (int i = 1; i < argc; i++)
	{
		size_t width, height;
		load_matrix(argv[i], &width, &height, 0);

		printf("Loaded %ld x %ld matrix\n", width, height);
	}

	return 0;
}


void
load_matrix(const char *filename, size_t *width, size_t *height, int x)
{
	FILE *f = fopen(filename, "rb");
	if (f == NULL)
	{
		err(-1, "Error opening %s", filename);
	}

	const size_t HEADER_SIZE = 16;

	uint64_t file_size;
	size_t n = fread(&file_size, sizeof(file_size), 1, f);
	if (n != 1)
	{
		err(-1, "Failed to load total file size from %s", filename);
	}

	uint32_t dimensions[2];
	n = fread(dimensions, sizeof(uint32_t), 2, f);
	if (n != 2)
	{
		err(-1, "Failed to load dimensions from %s", filename);
	}

	double matrix[dimensions[0] * dimensions[1]];
	printf("Loading %d x %d matrix into %p\n",
	       dimensions[0], dimensions[1], matrix);

        *width = dimensions[0];
        *height = dimensions[1];

	n = fread(matrix, 1, file_size - HEADER_SIZE, f);
	if (n != file_size - HEADER_SIZE)
	{
		err(-1, "Read %ld B from %s, not %ld",
                    n, filename, file_size - HEADER_SIZE);
	}

	printf("Result: %f\n", compute(matrix, dimensions[0], dimensions[1]));
}


double
compute(double *matrix, size_t width, size_t height)
{
	return 0;
}