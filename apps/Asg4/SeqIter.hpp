#include <iostream>
using namespace std;
template <typename T>
class SeqContainer {
protected:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
        bool isHiddenNode = false;
    };
    Node* head;
    Node* tail;
    void setupList()
    {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteListContents()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr)
        {
            temp = current.next;
            delete current;
            current = temp;
        }
    }
public:
    class const_iterator { ... };
    class iterator : public const_iterator { ... };
    SeqContainer()
    {
        setupList();
    }
    SeqContainer(T newData)
    {
        setupList();
        head->data = newData;
    }
    SeqContainer(SeqContainer& rhs)
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current.next;
            delete current;
            current = temp;
        }
        head = listr.head;
        tail = listr.tail;
    }
    virtual ~SeqContainer()
    {
        deleteListContents();
    }
    virtual iterator begin()
    {
        std::list<int>::iterator it;
        it = list.begin();
    }
    virtual iterator end()
    {
        std::list<int>::iterator it;
        it = list.end();
    }
    virtual const_iterator cbegin() const
    {

    }
    virtual const_iterator cend() const
    {

    }
    virtual iterator insert(iterator itr, const T& x)
    {

    }
    virtual iterator erase(iterator itr)
    {
        delete* itr;
    }
    virtual iterator erase(iterator from, iterator to)
    {

    }
