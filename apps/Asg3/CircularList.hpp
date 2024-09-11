// Used for help: https://www.geeksforgeeks.org/circular-linked-list/
// Used for help: https://www.geeksforgeeks.org/traversal-of-circular-linked-list/
// Used for help: https://www.geeksforgeeks.org/inheritance-in-c/
#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class CircularList : public List {
public:
	struct Node {
		T data;
		struct Node* next;
	};
	Node* one = createNode(3);
	Node* two = createNode(5);
	Node* three = createNode(9);
	//one->next = two;
	//two->next = three;
	//three->next = one;

    void push(struct Node** head_ref, T data)
    {
        struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
        ptr1->data = data;
        ptr1->next = *head_ref;
        if (*head_ref != NULL) {
            struct Node* temp = *head_ref;
            while (temp->next != *head_ref)
                temp = temp->next;
            temp->next = ptr1;
        }
        else
            ptr1->next = ptr1;
        *head_ref = ptr1;
    }
    void printList(struct Node* head)
    {
        struct Node* temp = head;
        if (head != NULL) {
            do {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != head);
        }

        printf("\n");
    }
    void deleteNode(struct Node** head, int key)
    {
        if (*head == NULL)
            return;
        if ((*head)->data == key && (*head)->next == *head) {
            free(*head);
            *head = NULL;
            return;
        }
        struct Node* last = *head, * d;
        if ((*head)->data == key) {
           while (last->next != *head)
                last = last->next;
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
            return;
        }
        while (last->next != *head && last->next->data != key) {
            last = last->next;
        }
        if (last->next->data == key) {
            d = last->next;
            last->next = d->next;
            free(d);
        }
        else
            cout << "Given node is not found in the list.\n";
    }
    void push(int data, Node* temp) 
    {
        if (this->head == nullptr) 
        {
            Node* node = new Node(data);
            this->head = node;
            node->next = this->head;
            return;
        }
        if (temp == nullptr) 
        {
            temp = this->head;
        }
        if (temp->next == this->head) 
        {
            Node* node = new Node(data);
            node->next = this->head;
            temp->next = node;
            return;
        }
        push(data, temp->next);
    }
    void circle(Node* temp, int startPos)
    {
        if (temp == nullptr) {
            temp = this->head;
        }
        if (temp->next == this->head) {
            cout << temp->data << endl;
            return;
        }
        cout << temp->data << "-->";
        traverse(temp->next);
    }
void circle(Node** head, int startPos)
{
    Node* temp = head;
    Node* start;
    if (temp != startPos)
    {
        temp->next;
    }
    else if (temp == startPos)
    {
        start = temp;
    }
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
};
