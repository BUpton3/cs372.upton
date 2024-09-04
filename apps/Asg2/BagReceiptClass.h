//Using Code from the lecture but changing some things
#include <iostream>
#include <random>
#include "Vector.h"
using namespace std;
template <typename Thing> 
class BagReceiptClass
{
private:
	vector<Thing*>& bagContents = new vector<Thing>;
	vector<int>& bagReceipts = new vector<int>;
public:
	int insert(Thing aThing);
	Thing& pop(int receipt);
	int size();
	int count();
};
