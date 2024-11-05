// Used for Help: https://www.geeksforgeeks.org/binary-search-functions-in-c-stl-binary_search-lower_bound-and-upper_bound/

#include "Tree.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include <istream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void fillvectors(vector<int> vect, int size) {
    int holder = 0;
    for (int i = 0; i < size; i++) {
        holder = rand() % 10000;
        vect.push_back(holder);
    }
}
template<typename T>
void isPresent(vector<T> vect, T searchFor, bool debugData = false) {
    if (binary_search(vect.begin(), vect.end(), searchFor))
        cout << searchFor << " exists in vector." << endl;
    else
        cout << searchFor << " does not exist in vector." << endl;
}

int main()
{
    // Initializing the vectors (not using arrays; sorry)
    vector<int> thousVect;
    vector<int> twenFiveVect;
    vector<int> fiveThousVect;
    vector<int> tenThousVect;
    vector<int> fifThousVect;
    cout << "vector initialization check" << endl;
    // Filling the vectors
    fillvectors(thousVect, 1000);
    fillvectors(twenFiveVect, 2500);
    fillvectors(fiveThousVect, 5000);
    fillvectors(tenThousVect, 10000);
    fillvectors(fifThousVect, 50000);
    cout << "vector fill check" << endl;
    // Initializing trees and using vectors from above
    Tree<int> thousTree, twenFiveTree, fiveThousTree, tenThousTree, fifThousTree;
    for (auto& it : thousVect) {
        thousTree.insertNode(it);
    }
    for (auto& it : twenFiveVect) {
        twenFiveTree.insertNode(it);
    }
    for (auto& it : fiveThousVect) {
        fiveThousTree.insertNode(it);
    }
    for (auto& it : tenThousVect) {
        tenThousTree.insertNode(it);
    }
    for (auto& it : fifThousVect) {
        fifThousTree.insertNode(it);
    }
    cout << "tree initialization check" << endl;
    // Randomly generating search values
    vector<int> searchVals;
    fillvectors(searchVals, 100);
    // Searching and timing
    // Vector search
    auto start = std::chrono::steady_clock::now();
    vector<int>::iterator myItr;
    for (myItr = searchVals.begin(); myItr != searchVals.end(); myItr++) {
        int holder = *myItr;
        isPresent(thousVect, holder, false);
        isPresent(twenFiveVect, holder, false);
        isPresent(fiveThousVect, holder, false);
        isPresent(tenThousVect, holder, false);
        isPresent(fifThousVect, holder, false);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration<double>(end - start);
    std::cout << "Vector search ended. Time taken: " << elapsed.count() << " seconds." << endl;
    // Tree search
    auto begin = std::chrono::steady_clock::now();
    for (myItr = searchVals.begin(); myItr != searchVals.end(); myItr++) {
        int holder = *myItr;
        thousTree.search(holder);
        twenFiveTree.search(holder);
        fiveThousTree.search(holder);
        tenThousTree.search(holder);
        fifThousTree.search(holder);
    }
    auto finish = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration<double>(finish - begin);
    std::cout << "Tree search ended. Time taken: " << duration.count() << " seconds." << endl;

    return 0;
}
