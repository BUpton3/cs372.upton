#include <iostream>
#include "SeqContainer.hpp"
using namespace std;
template <typename T>
class VectorClass {
private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 0;
public:
	int size()
	{
		return length;
	}
	int capacity()
	{
		return capacity;
	}
	void traverse()
	{
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}
	void put(int index)
	{
		T data;
		cout << "Insert data for spot " << index << ": ";
		cin >> data;
		if (index == capacity)
		{
			push_back(data);
		}
		else
		{
			arr[index] = data;
		}
	}
	void push_back(T data)
	{
		if (length == vCapacity)
		{
			expand(2 * vCapacity);
		}
		arr[length] = data;
		length++;
	}
	void expand(int newCapacity)
	{
		if (newCapacity > vCapacity)
		{
			T* temp = new T[newCapacity];
			for (int i = 0; i < length; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else
		{
			cout << "Vector::expand: new capacity is less than equal to current capacity.\n";
		}
	}
	T at(int index)
	{
		if (index < 0 || index > length)
		{
			cout << "Vector: index out of bounds on access." << endl;
			exit(1);
		}
		else
		{
			return arr[index];
		}
	}
	//void vectorNew();
	void vectorDelete()
	{
		delete[] arr;
		arr = nullptr;
	}
};
