//Used for help with dereferencing. I understand it now but the terminology messed me up: https://www.geeksforgeeks.org/cpp-dereferencing/

#include <iostream>
#include <string>
using namespace std;

void problemOne();
void problemTwo();
string problemThreeP1();
void problemThreeP2(string);

const int arraySize = 20;

int main()
{
	string pass;

	problemOne();
	cout << endl << endl;

	problemTwo();
	cout << endl << endl;

	pass = problemThreeP1();
	problemThreeP2(pass);
	cout << endl << endl;

	return 0;
}

void problemOne()
{
	int* arr = new int[arraySize];
	for (int count = 0; count < arraySize; count++)
	{
		arr[count] = count;
	}
	int* ptr = arr;
	delete arr;											//not sure if this was deleted right
	for (int count2 = 0; count2 < 10; count2++)
	{
		cout << ptr[count2] << " ";
	}
}

void problemTwo()
{
	int array[arraySize];
	for (int count = 0; count < arraySize; count++)
	{
		array[count] = count;
	}
	int* ptr1 = array;
	int* ptr2 = array;
	//delete ptr1;										//This causes the program to crash and I'm not sure if that is the point but I don't understand how to fix it/what it should look like
	cout << "Pointer 2 location: " << ptr2 << endl;
	for (int count = 0; count < 10; count++)
	{
		cout << ptr2[count] << " ";
	}
}

string problemThreeP1()
{
	string* ptr = new string("abcdefghijkl");
	string passing = *ptr;
	return passing;
}

void problemThreeP2(string pointrStr)
{
	string word = pointrStr;
	cout << word;
}
