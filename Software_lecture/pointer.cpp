#include <iostream>


int foo(void);
double bar(void);


int main()
{
	int n = 42;
	std::cout
		<< "The value of n is:    " << n << std::endl
		<< "The address of n is:  " << &n << std::endl
		;

	// Now let's call foo() and see what addresses live on the stack...
	std::cout << foo() << std::endl;

	return 0;
}


int foo()
{
	int m = 10;
	std::cout << "The address of m is:  " << &m << std::endl;

	return m * bar();
}


double bar()
{
	double x = 3.1415926;
	std::cout << "The address of x is:  " << &x << std::endl;

	return x;
}