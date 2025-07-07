#include <stdio.h>
#include <unistd.h>


int main()
{
	printf("My UID is: %d\n", getuid()); // This means that the user's ID is a signed digital integer. When I run it I get 1000 every time. I am 1000.
	return 0;
}