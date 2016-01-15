#include "list.hpp"
#include <iostream>
using namespace std;

Node* List::insert(Node* head, int val, int pos) {
	if (pos == 0) {
		Node* x = new Node(val, head);
		return x;
	} else {
		Node* iterator = head;
		for (int i = 1; i < pos; i++) {
			iterator = iterator->getNext();
		}
		Node* x = new Node(val, iterator->getNext());
		iterator->setNext(x);
	}
	return head;
}

Node* List::remove(Node* head, int pos) {
	if (pos == 0) {
		return (*head).getNext();
	}
	Node* iterator = head;
	for (int i = 1; i < pos; i++) {
		iterator = iterator->getNext();
	}
	Node* toBeDeleted = iterator->getNext();
	iterator->setNext(toBeDeleted->getNext());
	return head;
}

int List::size(Node* head) {
	Node* iterator = head;
	if (!head) {
		return 0;
	}
	int length = 1;
	iterator = iterator->getNext();
	while (iterator) {
		length++;
		iterator = iterator->getNext();
	}
	return length;
}

Node* List::reverse(Node* head) {
	if (!head) {
		return NULL;
	}
	Node* previous = head;
	Node* current = previous->getNext();
	if (!current) {
		return head;
	}
	Node* next = current->getNext();
	previous->setNext(NULL);
	current->setNext(previous);
	while (next) {
		previous = current;
		current = next;
		next = current->getNext();
		current->setNext(previous);
	}
	return current;
}

int List::cycle_size(Node* head) {
	Node* iterator = head;
	Node* addresses[1000000];
	if (!head) {
		return 0;
	}
	int addr_len = 0;
	Node* cycle_start = NULL;
	while (!cycle_start) {
		for (int i = 0; i < addr_len; i++) {
			if (addresses[i] == iterator) {
				cycle_start = iterator;
			}
		}
		addresses[addr_len] = iterator;
		addr_len++;
		iterator = iterator->getNext();
		if (!iterator) {
			return 0;
		}
	}
	int cycle_size = 1;
	while(iterator != cycle_start) {
		cycle_size++;
		iterator = iterator->getNext();
	}
	return cycle_size;
}