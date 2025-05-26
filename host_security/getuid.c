#include <stdio.h>
#include <unistd.h>


int main()
{
	printf("My UID is: %d\n", getuid());
	return 0;
}