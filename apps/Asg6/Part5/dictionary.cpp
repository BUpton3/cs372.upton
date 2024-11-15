// Used for help: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
// Used for help: https://www.geeksforgeeks.org/how-to-create-a-dictionary-in-cpp/
#include "dictionaryclass.hpp"
#include <iostream>
#include <map>
using namespace std;

int main() {

    // Create an empty dictionary using std::map
    map<string, string> dict;

    // Insert key-value pairs
    dict["Hockey"] = "A winter sport played on ice with sticks and rubber pucks.";
    dict["Books"] = "Bound paper which contains printed matter.";
    dict["Legos"] = "A popular plastic building toy.";

    for (auto it : dict)
        cout << it.first << ": " << it.second << endl;

    return 0;
}
