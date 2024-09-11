#include <iostream>
#include <random>
#include "List.hpp"
using namespace std;
template <typename Thing>
class Bag : public List
{
private:
	vector<Thing*>& bagContents = new vector<Thing>;
	vector<int>& bagReceipts = new vector<int>;
public:
	int insert(Thing aThing) {
		bagContents.push_back(aThing);
		int index = 0;
		int receipt = 0;
		int i = bagContents.size();
		while (i < bagReceipts.size - 1 && bagReceipts[index] != 0)
		{
			index++;
		}
		if (index == bagReceipts.size - 1)
		{
			bagContents.push_back(aThing);
			receipt = bagContents.size() - 1;
			bagReceipts.push_back(receipt);
		}
		else
		{
			bagContents[index] = aThing;
			receipt = index;
		}
	}
	Thing& pop(int receipt) {
		Thing theThingBeingPopped;
		int i = bagContents.size();
		while ((i < 0) && (bagReceipts[i] != receipt))
		{
			if (bagReceipts[i] = receipt)
			{
				theThingBeingPopped = bagContents[i];
				bagReceipts[i] = 0;
			}
		};
		return theThingBeingPopped;
	}
	int size() {
		return bagContents.capacity();
	}
	int count() {
		return bagContents.size();
	}
};
