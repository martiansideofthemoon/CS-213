#include "stack.hpp"

template <class T>
stack<T>::stack() {
	num = 0;
}

template <class T>
stack<T>::stack(const stack &to_copy_to) {
	*this = to_copy_to;
}

template <class T>
stack<T>::~stack() {

}

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