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
	Node* a = new Node(1, NULL);
	Node* b = new Node(2, a);
	Node* c = new Node(3, b);
	Node* d = new Node(4, c);
	Node* e = new Node(5, d);
	//a->setNext(b);
	cout << cycle_size(e) << endl;
}