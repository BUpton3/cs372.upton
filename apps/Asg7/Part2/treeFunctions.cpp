#include <iostream>
#include <vector>
#include "Tree.hpp"
using namespace std;
int main()
{
    int size;
    vector<int> vect;
    cout << "How large do you want the vector?: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        int holder = 0;
        holder = rand() % 10000;
        vect.push_back(holder);
    }
    sort(vect.begin(), vect.end());
    Tree<int> tree;
    for (auto& it : vect) {
        tree.insertNode(it);
    }
    cout << "\n\nInorder traversal of sorted tree:\n";
    tree.inorder();

    return 0;
}
