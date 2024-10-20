// Used for Help: https://www.geeksforgeeks.org/smart-pointers-cpp/
// 

#include <cassert>

template <typename T>
class List
{
private:
	struct Node {
		Node(T newData) {
			data = newData;
		}
		std::unique_ptr* next = nullptr;
		std::unique_ptr* prev = nullptr;
		T data;
		Node(T data) : data(data), next(nullptr) {}
	};
	size_t nodeCount = 0;
	std::unique_ptr* head = nullptr;
	std::unique_ptr* tail = nullptr;

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
		std::unique_ptr* currentNode = head;
		while (currentNode != nullptr) {
			doIt(currentNode->data);
			currentNode = currentNode->next;
		}
		delete currentNode;
	}

	void travprint() {
		std::unique_ptr* currentNode = head;
		while (currentNode != nullptr) {
			doIt(currentNode->data);
			std::cout << data << " ";
			currentNode = currentNode->next;
		}
		delete currentNode;
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

template <typename T>
class SmartPtr {
	T* ptr;
public:
	explicit SmartPtr(T* p = NULL) {
		ptr = p;
	}
	~SmartPtr() {
		delete (ptr);
	}
	T& operator*() {
		return *ptr;
	}
};
