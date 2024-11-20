#include <iostream>
#include <list>
#include <iterator>
#include "finalProgramming.hpp"
using namespace std;

template <typename T>
void partitions(T split, list<T>& main, list<T>& lessThan, list<T>& greater) {
    for (auto m : main) {
        if (m > split) {
            greater.push_back(m);
        }
        else {
            lessThan.push_back(m);
        }
    }
}
template <typename T>
void puttingTogether(list<T>& lessThan, list<T>& greaterThan, list<T>& together) {
    for (auto c : lessThan)
        together.push_back(c);
    for (auto d : greaterThan)
        together.push_back(d);

}

template<typename T>
typename std::list<T>::iterator partition(std::list<T>& lst, typename std::list<T>::iterator low, typename std::list<T>::iterator high) {
    T pivot = *high; 
    auto i = low;

    for (auto j = low; j != high; ++j) {
        if (*j < pivot) {
            std::swap(*i, *j);
            ++i;
        }
    }
    std::swap(*i, *high);
    return i; 
}
template<typename T>
void quicksort(std::list<T>& lst, typename std::list<T>::iterator low, typename std::list<T>::iterator high) {
    if (low != high) {
        auto p = partition(lst, low, high);
        if (p != low) {
            quicksort(lst, low, std::prev(p));
        }
        if (std::next(p) != high) {
            quicksort(lst, std::next(p), high); 
        }
    }
}
template<typename T>
void quicksort(std::list<T>& lst) {
    if (!lst.empty()) {
        quicksort(lst, lst.begin(), std::prev(lst.end()));
    }
}




int main()
{
    list<int> theList, lessList, greaterList;
    int holder;
    for (int x = 0; x < 50; x++) {
        holder = rand() % 100;
        theList.push_back(holder);
    }
    cout << "The List: " << endl;
    for (auto v : theList)
        cout << v << " ";
    cout << endl << endl;

    int splitter = 46;
    partitions(splitter, theList, lessList, greaterList);

    cout << "Greater Than: " << endl;
    for (auto a : greaterList)
        cout << a << " ";
    cout << endl;
    cout << "Less Than: " << endl;
    for (auto b : lessList)
        cout << b << " ";
    cout << endl << endl;

    list<int> newList;
    puttingTogether(lessList, greaterList, newList);
    cout << "List Together: " << endl;
    for (auto e : newList)
        cout << e << " ";
    cout << endl << endl;
    newList.sort();
    cout << "Sorted List: " << endl;
    for (auto f : newList)
        cout << f << " ";

    return 0;
}
