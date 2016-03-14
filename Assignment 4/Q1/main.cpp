#include "minMaxHeap.hpp"
#include <iostream>
using namespace std;

template<class T>
class subPredicate: public Predicate<T> {
	public:
		bool toDelete(T elem) {
			if (elem % 2 == 0) {
				return true;
			} else {
				return false;
			}
		}
};
int main() {
	MinMaxHeap<int> a;
	char command;
	cin >> command;
	while (command != 'q') {
		switch(command) {
			case 'p':
				a.printVector();
				break;
			case 'i':
				int b;
				cin >> b;
				a.insert(b);
				break;
			case 'g':
				cout << a.getMax() << endl;
				break;
			case 'h':
				cout << a.getMin() << endl;
				break;
			case 'd':
				a.deleteMax();
				break;
			case 'e':
				a.deleteMin();
				break;
			case 'f':
				subPredicate<int> c;
				a.deleteElems(c);
				break;
		}
		cin >> command;
	}
}