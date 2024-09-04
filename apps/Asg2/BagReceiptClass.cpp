//Using Code from the lecture but changing some things
#include "BagReceiptClass.h"

template <typename Thing>int BagReceiptClass<Thing>::insert(Thing aThing)
{
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
			//Just use the index of the thing as receipt
			receipt = bagContents.size() - 1;
			bagReceipts.push_back(receipt);
	}
	else
	{
		bagContents[index] = aThing;
			receipt = index;
	}
}
template <typename Thing>Thing& BagReceiptClass<Thing>::pop(int receipt)
{
	Thing theThingBeingPopped; //Address initialization
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
template <typename Thing>int BagReceiptClass<Thing>::size()
{
	return bagContents.capacity();
}
template <typename Thing>int BagReceiptClass<Thing>::count()
{
	return bagContents.size();
}
