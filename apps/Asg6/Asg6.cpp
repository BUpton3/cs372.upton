#include "Tree.hpp"
#include <iostream>
#include <queue>
using namespace std;

int main() {
    Tree<int> tree;
    vector<int> aTree({ 45,74,28,32,45,44, 100 });
    for (auto& it : aTree) {
        tree.insertNode(it);
    }
    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    cout << "Deleting 28 from Tree. \n";
    tree.deleteNode(28);
    cout << "Inorder traversal after deletion: ";
    tree.inorder();
    
    return 0;
}
