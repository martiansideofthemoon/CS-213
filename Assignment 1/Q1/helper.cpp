#include <iostream>
#include "list.hpp"
using namespace std;

void print(Node* x) {
	while (x) {
		cout << x->getVal() << " ";
		x = x->getNext();
	}
	cout << endl;
}

int main() {
	List l;
}