// Breah Upton
// 00087865
// bupton3@my.athens.edu

#include <iostream>
#include <random>
#include "Vector.h"
#include "Array.h"
#include "BagReceiptClass.h"
using namespace std;

int main()
{
	// I can not figure out what is wrong with lines 16 and 17.
	// I did everything I thought was right between the functions and header files.
	// I searched every google page I could find on ways to fix this and came up with nothing
	// so I am thoroughly confused.
	// I believe that my problem is because of the template classes but I can't figure it out
	// Plan on using this for help: https://www.geeksforgeeks.org/templates-cpp/

	VectorClass vectClass;		
	ArrayClass arrClass;		
	BagReceiptClass bagClass;

	cout << "\tAssignment 2\t" << endl;

	// Testing the Vector Class
	cout << "\n\n\tTesting the Vector Class\n";
	int vectSize;
	cout << "Vector Size: ";
	cin >> vectSize;
	vectClass.expand(vectSize);
	for (int counter = 0; counter < vectSize; counter++)
	{
		vectClass.put(counter);
	}
	vectClass.traverse();
	vectClass.vectorDelete();

	// Testing the Array Class
	cout << "\n\n\tTesting the Array Class\n";
	int arrsize;
	cout << "Array Size: ";
	cin >> arrsize;
	arrClass.getSize(arrsize);
	for (int count = 0; count < arrsize; count++)
	{
		arrClass.put(count);
	}
	arrClass.printArray();
	arrClass.deleteArray();

	// Testing the Bag Receipts Class
	cout << "\n\n\tTesting the Bag Receipt Class\n";


	// End Main
	return 0;
}
