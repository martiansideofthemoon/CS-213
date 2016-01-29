#include "stack.hpp"
#include <iostream>

template <class T>
void stack<T>::push(T n) {
	elements.push_front(n);
	num++;
}

template <class T>
int stack<T>::top(T* top_element) {
	if (num == 0) {
		return -1;
	}
	*top_element = *elements.begin();
	return 1;
}

template <class T>
void stack<T>::pop() {
	if (num > 0) {
		elements.pop_front();
		num--;
	}
}

template <class T>
int stack<T>::size() {
	return num;
}