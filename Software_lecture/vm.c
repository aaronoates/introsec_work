#include <stdio.h>
#include <stdlib.h>

int x;

int main()
{
	printf("C pointer demo\n\n");

	printf("&main:   %p\n\n", main);

	printf(" x:      %d\n", x);

	int *xp = &x;
	printf("&x:      %p\n", xp);

	int y;
	printf(" y:      %d\n", y);

	int *yp = &y;
	printf("&y:      %p\n", yp);

	int *z = malloc(10 * sizeof(int));
	printf(" z:      %p\n", z);
	printf("*z:      %d\n", *z);
	printf("*(z+5):  %d\n", *(z+5));

	//int *oops = 0; //z - 100000;
	//int n = *oops;

	// Let's try a use-after-free...
	free(z);
	printf("*z:      %d\n", *z);

	return 0;
}