// used for help :https://www.geeksforgeeks.org/hash-table-data-structure/
// figuring out fully adding doubleHash and quadratic Probing to this

#include <iostream>
#include <vector>
using namespace std;

// hash function
struct Hash {
    int bucket;
    vector<vector<int>> table;
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }
    int hashFunction(int x) {
        return (x % bucket);
    }
    void displayHash() {
        for (int i = 0; i < bucket; i++) {
            cout << i;
            for (int x : table[i]) {
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
    Hash(int b) {
        this->bucket = b;
        table.resize(bucket);
    }
};

int main()
{
    vector<int> testVect = { 20, 43, 15, 11, 9, 6, 10 };
    Hash h(7);
    for (int key : testVect)
        h.insertItem(key);
    h.deleteItem(43);
    h.displayHash();

    return 0;
}
