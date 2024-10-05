// Breah Upton 00087865 bupton3@my.athens.edu
// Used for help: https://www.geeksforgeeks.org/list-cpp-stl/
// Used for help: https://www.geeksforgeeks.org/josephus-problem/
// Used for help: https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

void printList(list<int> listing);
void hotPotato(list<int> people, int k, int index);

int main()
{
	int players, k;
	int hotPot = 5;
	cout << "Enter number of players: ";
	cin >> players;
	cout << "Eliminate players at: ";
	cin >> k;
	k--;
	int index = 0;

	list<int> person;
	for (int i = 1; i <= players; i++) {
		person.push_back(i);
	}

	hotPotato(person, k, index);

	return 0;
}

void printList(list<int> listing)
{
	list<int>::iterator it;
	for (it = listing.begin(); it != listing.end(); ++it)
		cout << *it << '\t';
	cout << '\n';
}

void hotPotato(list<int> people, int k, int index)
{
	list<int>::iterator it2 = people.begin();
	if (people.size() == 1)
	{
		it2 = people.begin();
		cout << *it2 << endl;
		return;
	}
	index = ((index + k) % people.size());
	it2 = people.begin();
	advance(it2, index);
	people.erase(it2);
	hotPotato(people, k, index);
}
