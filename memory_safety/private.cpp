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

	// Can we access y and z directly?

	// Can we construct pointers or references to them?

	// How about x?

	// What are the bytes within e?

	// Now how about x?

	return 0;
}