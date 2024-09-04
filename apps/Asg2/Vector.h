#include <iostream>
using namespace std;
template <typename V>
class VectorClass {
private:
	V* arr = new V[1];
	int vCapacity = 1;
	int length = 0;
	public:
	int size();
	int capacity();
	void traverse();
	void put(int index);
	void push_back(V data);
	void expand(int newCapacity);
	V at(int index);
	//void vectorNew();
	void vectorDelete();
};
