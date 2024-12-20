// Breah Upton 00087865 bupton3@My.athens.edu
// Used For Help: https://cs226fa22.github.io/notes/22-hashing/step11.html#:~:text=The%20solution%20is%20lazy%20deletion:%20flag%20the%20item%20as%20deleted
// Used For Help: https://www.geeksforgeeks.org/cpp-program-for-searching-an-element-in-a-linked-list/
// Used For Help: https://www.geeksforgeeks.org/delete-occurrences-given-key-linked-list/
#include <cassert>

template <typename T>
class List
{
private:
	struct Node {
		Node(T newData) {
			data = newData;
		}
		Node* next = nullptr;
		Node* prev = nullptr;
		T data;
	};
	size_t nodeCount = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	void copy(const List<T>& other) {
		Node* point = other.head;
		while (point != nullptr) {
			push_back(point->data);
			point = point->next;
		}
	}
public:
	List() {}
	List(T item) {
		push_back(item);
	}
	List(const List<T>& other) {
		copy(other);
	}
	List<T>& operator+=(const List<T>& other) {
		clear();
		copy(other);
	}
	~List() {
		clear();
	}

	unsigned int size() {
		return nodeCount;
	}
	void clear() {
		while (!empty()) {
			pop_back();
		}
	}
	bool empty() {
		return (head->next == tail);
	}

	void push_front(T data) {
		Node* newNode = new Node(data);
		if (!empty()) {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else {
			head = newNode;
			tail = newNode;
		}
		nodeCount++;
	}
	void push_back(T data) {
		Node* newNode = new Node(data);
		if (!empty()) {
			tail->prev = newNode;
			newNode->prev = head;
			tail = newNode;
		}
		else {
			head = newNode;
			tail = newNode;
		}
		nodeCount++;
	}

	void pop_front() {
		assert(!empty());
		Node* temp = head;
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		else {
			tail = nullptr;
		}
		delete temp;
		nodeCount--;
	}
	void pop_back() {
		assert(!empty());
		Node* temp = tail;
		tail = tail->prev;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
		delete temp;
		nodeCount--;
	}

	T& front() {
		assert(!empty());
		return head->data;
	}
	T& back() {
		assert(!empty());
		return tail->data;
	}

	iterator begin() {
		return head->next;
	}
	iterator end() {
		return tail;
	}

	const_iterator cbegin() const {
		return head->next;
	}
	const_iterator cend() const {
		return tail;
	}

	void traverse(void(*doIt)(T data)) {
		Node* currentNode = head;
		while (currentNode != nullptr) {
			doIt(currentNode->data);
			currentNode = currentNode->next;
		}
	}

	void travprint() {
		Node* currentNode = head;
		while (currentNode != nullptr) {
			doIt(currentNode->data);
			std::cout << data << " ";
			currentNode = currentNode->next;
		}
	}

	void lazyMark(T element) {		// This is marking for deletion
		T deleteKey = 01;
		Node* currentNode = head;
		while (currentNode != nullptr) {
			if (currentNode->data == deleteKey)
				currentNode->data = deleteKey;
			return;
		}
	}
	void lazyDelete() {			// This is searching for the deletion mark and then deleting
		T deleteKey = 01;
		Node* currentNode = head, * prevNode = nullptr;
		while (currentNode != nullptr) {
			if (currentNode->data == deleteKey) {
				if (prevNode == nullptr) {
					head = currentNode->next;
				}
				else {
					prevNode->next = currentNode->next;
				}
				currentNode = currentNode->next;
			}
			else {
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
		}
		return;
	}

};





template <typename T>
class const_iterator {
protected:
	Node* current;
	T& retrieve() const { return current->data; }
	const_iterator(Node* p) : current(p) { }
	friend class List<T>;
public:
	const_iterator() : current(nullptr) { }
	T& operator*() const {
		return retrieve();
	}
	const_iterator& operator++() {
		current = current->next;
		return *this;
	}
	const_iterator  operator++(int) {
		const_iterator old = *this;
		++(*this);
		return old;
	}
	bool operator==(const const_iterator& rhs) const {
		return current == rhs.current;
	}
	bool operator!=(const const_iterator& rhs) const {
		return !(*this == rhs);
	}
};

template <typename T>
class iterator : public const_iterator {
protected:
	iterator(Node* p) : const_iterator(p) { }
	friend class List<T>;
public:
	iterator() { }
	T& operator *() {
		return const_iterator::retrieve();
	}
	const T& operator* () const {
		return const_iterator::operator*();
	}
	iterator& operator++ () {
		this->current = const_iterator::current->next;
		return *this;
	}
	iterator operator++ (int) {
		iterator old = *this;
		**(*this);
		return old;
	}
};
