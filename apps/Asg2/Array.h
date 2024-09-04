#include <iostream>
using namespace std;
template <typename P> 
class ArrayClass {
private:
	int aCapacity = 1;
	int size_t;
	P* arr2 = new P[size_t];	//Believe this should dynamically allocate an array. The new statement with a pointer to it.
	
public:
	void getSize(int sizeP);
	void printArray();
	void put(int index);
	P at(int index);
	//void declareArray();
	void deleteArray();
};
