#include <iostream>
#include <cassert>
#include <cstddef>
using namespace std;

template <class RecordType>
class Table {
public:
    static const std::size_t CAPACITY = 811;

    Table() : used(0) {
        for (std::size_t i = 0; i < CAPACITY; ++i) {
            data[i].key = NEVERUSED;
        }
    }
    void insert(const RecordType& entry) {
        bool alreadyPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            std::size_t i = 1; // Step counter for quadratic probing
            while (!isVacant(index)) {
                index = quadProbe(index, i);
                ++i;
            }
            data[index] = entry;
            ++used;
        }
    }
    void remove(int key) {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }
    bool isPresent(int key) const {
        bool found;
        std::size_t index;
        findIndex(key, found, index);
        return found;
    }
    void find(int key, bool& found, RecordType& result) const {
        std::size_t index;
        findIndex(key, found, index);
        if (found) {
            result = data[index];
        }
    }
    std::size_t size() const { return used; }

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;
    std::size_t hash(int key) const {
        return key % CAPACITY; // Simple hash function
    }
    std::size_t quadProbe(std::size_t index, std::size_t i) const {
        return (index + i * i) % CAPACITY; // Quadratic probing
    }
    void findIndex(int key, bool& found, std::size_t& index) const {
        std::size_t count = 0;
        index = hash(key);
        while ((count < CAPACITY) && (!neverUsed(index)) && (data[index].key != key)) {
            ++count;
            index = quadProbe(index, count); // Use quadProbe for searching
        }
        found = (data[index].key == key);
    }
    bool neverUsed(std::size_t index) const { return (index == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (data[index].key == PREVIOUSLYUSED || data[index].key == NEVERUSED); }
};
int main() {
    Table<int> table;
    int r1 = { 1 };
    int r2 = { 2 };
    int r3 = { 3 };
    table.insert(r1);
    table.insert(r2);
    table.insert(r3);
    bool found;
    int result;
    table.find(2, found, result);
    if (found) {
        cout << "Found!";
    }
    return 0;
}
