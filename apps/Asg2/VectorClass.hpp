// Used for help: https://www.geeksforgeeks.org/templates-cpp/
#include "Vector.h"

/*
template <typename T> void VectorClass<T>::vectorNew()
{
    T* arr = new T[1];
    vCapacity = 1;
    length = 0;
}
*/

template <typename V> void VectorClass<V>::vectorDelete()
{
    delete[] arr;
    arr = nullptr;
}
template <typename V> void VectorClass<V>::push_back(V data)
{
    if (length == vCapacity) {
        expand(2 * vCapacity);
    }
    arr[length] = data;
    length++;
}
template <typename V> void VectorClass<V>::put(int index)
{
    V data;
    cout << "Insert data for spot " << index << ": ";
    cin >> data;
    if (index == vCapacity)
    {
        push_back(data);
    }
    else
    {
        arr[index] = data;
    }
}
template <typename V> V VectorClass<V>::at(int index)
{
    if (index < 0 || index > length) {
        cerr << "Vector: index out of bounds on access" << endl;
        exit(1);
    }
    else {
        return arr[index];
    }
}
template <typename V> int VectorClass<V>::size()
{
    return length;
}
template <typename V> int VectorClass<V>::capacity()
{
    return vCapacity;
}
template <typename V> void VectorClass<V>::traverse()
{
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}

template <typename V> void VectorClass<V>::expand(int newCapacity)
{
    if (newCapacity > vCapacity) {
        V* temp = new V[newCapacity];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        vCapacity = newCapacity;
        arr = temp;
    }
    else {
        std::cerr << "vector::expand: new capacity is less than equal to current\n";
    }
}
