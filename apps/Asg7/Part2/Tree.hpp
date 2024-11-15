// Used for Help: https://www.geeksforgeeks.org/binary-tree-in-cpp/
// Used for help: https://codereview.stackexchange.com/questions/248306/using-smart-pointers-to-construct-binary-search-tree
// Used for help: https://www.geeksforgeeks.org/smart-pointers-cpp/
// Used for help: https://medium.com/swlh/c-smart-pointers-and-how-to-write-your-own-c0adcbdce04f

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* deleteRecursive(Node<T>* current, T value) {
        if (current == nullptr) return nullptr;

        if (current->data == value) {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }
            if (current->left == nullptr) {
                Node<T>* temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            }

            Node<T>* successor = findMin(current->right);
            current->data = successor->data;
            current->right = deleteRecursive(current->right, successor->data);
        }
        else {
            current->left = deleteRecursive(current->left, value);
            current->right = deleteRecursive(current->right, value);
        }
        return current;
    }
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
    bool searchRecursive(Node<T>* current, T value) {
        if (current == nullptr) return false;
        if (current->data == value) return true;
        return searchRecursive(current->left, value) || searchRecursive(current->right, value);
    }
    void inorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            cout << node->data << endl;
            inorderRecursive(node->right);
        }
    }
    void preorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }
    void postorderRecursive(Node<T>* node) {
        if (node != nullptr) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }
public:
    Tree() : root(nullptr) {}
    void insertNode(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }
    void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }
    bool search(T value) {
        return searchRecursive(root, value);
    }
    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }
    void preorder() {
        preorderRecursive(root);
        cout << endl;
    }
    void postorder() {
        postorderRecursive(root);
        cout << endl;
    }
};
