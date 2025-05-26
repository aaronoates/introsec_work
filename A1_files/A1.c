#include <stdio.h>
#include <string.h>

void foo(const int data[], int len)
{
	printf("data len: %d\n", len);
	printf("data: %d %d\n", data[0], data[1]);
}

void bar(const char *buffer, int len)
{
	const int *integers = (int*) buffer;

	foo(integers, len / 4);
}

int main()
{
	char message[16];
	strcpy(message, "Hello, world!\n");
	int len = strnlen(message, sizeof(message));

	bar(message, len);

	return 0;
}