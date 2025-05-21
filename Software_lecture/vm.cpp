#include <iostream>
using namespace std;

int x;

int main()
{
	cout << "C++ pointer demo" << endl << endl;

	cout << "&main:   " << reinterpret_cast<void*>(&main) << endl << endl;

	cout << " x:      " << x << endl;

	int *xp = &x;
	cout << "&x:      " << xp << endl;

	int y;
	cout << " y:      " << y << endl;

	int *yp = &y;
	cout << "&y:      " << yp << endl;

	int *z = new int[10];
	cout << " z:      " << z << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "*(z+" << i << "):   " << *(z+i) << endl;
	}

	/*
	int *oops = z - 100000;
	cout << "oops: " << oops << endl;
	cout << "*oops: " << *oops << endl;
	*/

	// Assign to z[0]:
	*z = 100;
	cout << *z << endl;

	// How about a C++ use-after-free?
	delete [] z;
	cout << *z << endl;

	return 0;
}