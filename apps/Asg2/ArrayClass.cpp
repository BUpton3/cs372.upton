// Used for help: https://www.geeksforgeeks.org/templates-cpp/
#include "Array.h"
#include <iostream>
using namespace std;

template <typename P> void ArrayClass<P>::getSize(int sizeT)
{
    size_t = sizeT;
}
template <typename P> void ArrayClass<P>::put(int index)
{
    P data;
    cout << "Insert data for spot " << index << ": ";
    cin >> data;
    arr2[index] = data;
}
template <typename P> P ArrayClass<P>::at(int index)
{
    if (index < 0 || index > size_t) {
        cerr << "Array: index out of bounds on access" << endl;
        exit(1);
    }
    else {
        return arr2[index];
    }
}
template <typename P> void ArrayClass<P>::printArray()
{
    for (int i = 0; i < size_t; i++)
    {
        cout << arr2[i] << endl;
    }
    cout << endl;
}
/*
template <typename T> void ArrayClass<T>::declareArray()
{
    T* arr = new T arr2[size_t];
    aCapacity = size_t;
}
*/
template <typename P> void ArrayClass<P>::deleteArray()
{
    delete[] arr2;
    arr2 = nullptr;
}
