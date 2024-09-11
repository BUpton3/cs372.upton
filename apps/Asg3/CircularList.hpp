#include <iostream>
#include <random>
#include "List.hpp"
using namespace std;
template <typename Thing>
class CircularList : public List
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
