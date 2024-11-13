#include <iostream>
#include <list>
#include <map>

using namespace std;

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>
> class dictionary {
	pair(Key, T) : pair;

	T get(Key key) {

	}
	void set(Key key, T value) {

	}
	list<Key> getKeys() {
		for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			key.push_back(it->first);
			cout << "Key: " << it->first << endl;
		}
	}
	list<T> getValues() {
		for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			value.push_back(it->second);
			cout << "Value: " << it->second << endl;
		}
	}
	operator[](const Key& key) {

	}
};
