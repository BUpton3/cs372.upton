#include <iostream>
#include "SeqContainer.hpp"
using namespace std;
template <typename T>
class ArrayClass {
private:
	int aCapacity = 1;
	int size_t;
	T* arr2 = new T[size_t];	//Believe this should dynamically allocate an array. The new statement with a pointer to it.

public:
	void getSize(int sizeP)
	{
		size_t = sizeT;
	}
	void printArray()
	{
    int* ptr = arr2;
		for (int i = 0; i < size_t; i++)
      court << *(ptr+1);
		cout << endl;
	}
	void put(int index)
	{
		T data;
		cout << "Insert data for spot " << index << ": ";
		cin >> data;
		arr2[index] = data;
	}
	T at(int index)
	{
		if (index < 0 || index > size_t)
		{
			cout << "Array: index out of bounds on access." << endl;
			exit(1);
		}
		else
		{
			return arr2[index];
		}
	}
	//void declareArray();
	void deleteArray()
	{
		delete[] arr2;
		arr2 = nullptr;
	}
};
