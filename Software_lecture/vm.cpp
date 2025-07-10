#include <iostream>
using namespace std;

int x;

int main()
{
	cout << "C++ pointer demo" << endl << endl;

	void* addMain = reinterpret_cast<void*>(&main);

	cout << "&main:   " << addMain << endl << endl;

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
	z[0] = 100;
	z[1] = 200;
	for (int i = 0; i < 10; i++){
		cout << "*(z+" << i << "):   " << *(z+i) << endl;
	}
	


	// How about a C++ use-after-free?
	delete [] z;
	cout << *z << endl; //segmentation fault

	return 0;
}