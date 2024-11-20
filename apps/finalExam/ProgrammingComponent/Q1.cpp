#include <iostream>
#include <vector>
#include "Q1.hpp"
using namespace std;
int main()
{
    Tree<int> tree;
    vector<int> aTree({ 45,74,28,32,45,44, 100 });
    for (auto& it : aTree) {
        tree.insertNode(it);
    }

    // counting the Nodes
    // used for help: https://www.geeksforgeeks.org/count-number-of-nodes-in-a-complete-binary-tree/
    tree.nodeCount();

    // counting internal nodes
    // used for help: https://www.geeksforgeeks.org/print-all-internal-nodes-of-a-binary-tree/
    tree.internalNodeCount();

    // external path length
    // used for help: Microsoft Bing AI programming tool. Specific search was "c++ how to add up external nodes in a tree"
    tree.externalPath();

    return 0;
}
