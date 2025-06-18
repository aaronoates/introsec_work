#include <iostream>
using namespace std;

class Example
{
public:
	Example(int x, int y, int z)
		: x_(x), y_(y), z_(z)
	{
	}

	int x() const
	{
		return x_;
	}

	int y() const
	{	
		return y_;
	}

	int z() const
	{
		return z_;
	}

private:
	int x_;

public:
	const int y_;
	const int z_;
};


int main()
{
	cout << "Hello, world!" << endl;

	Example e(1, 2, 3);

	cout << "x: " << e.x() << endl;
	cout << "y: " << e.y_ << endl;
	cout << "z: " << e.z_ << endl;
	int a = e.y_;
	int* pa = &a;
	int** ppa = &pa;

	
	cout << "value of A: " << a << endl;
	cout << "address of A: " << &a << endl;
	cout << "current value of pa " << pa << endl;
	cout << "value pointed to by pa " << *pa << endl;
	cout << "value of ppa  " << ppa << endl;
	cout << "address of ppa " << &ppa << endl;
	cout << "value pointed to by ppa " << *ppa << endl;
	cout << "value pointed to by pointer pointed to by ppa " << **ppa << endl;
	cout << "size of e: " << sizeof(e) << " bytes" << endl;

	
	
	
	
	


	// Can we access y and z directly?
	// Yes because they are public.

	// Can we construct pointers or references to them?
	// Yes because I just did it.
	// How about x?
	//yes 

	// What are the bytes within e?
	//12 bytes, 4 for each variable.
	// Now how about x?
    // what
	return 0;
}