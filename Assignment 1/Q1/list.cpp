#include "list.hpp"
#include <iostream>
using namespace std;

Node* insert(Node* head, int val, int pos) {
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

Node* remove(Node* head, int pos) {
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

int size(Node* head) {
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

Node* reverse(Node* head) {
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

int cycle_size(Node* head) {
	int length = 0;
	Node* slow_ptr = head;
	Node* fast_ptr = head;
	while(slow_ptr && fast_ptr) {
		fast_ptr = fast_ptr->getNext()->getNext();
		slow_ptr = slow_ptr->getNext();
		if(slow_ptr == fast_ptr) {
			fast_ptr = fast_ptr->getNext();
			length++;
			while (fast_ptr != slow_ptr) {
				fast_ptr = fast_ptr->getNext();
				length++;
			}
		}
	}
	return length;
}