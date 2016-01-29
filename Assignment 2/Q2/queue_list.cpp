#include "queue_list.hpp"
using namespace std;

template <class T>
queue_list<T>::queue_list() {
	num = 0;
}

template <class T>
queue_list<T>::queue_list(const queue_list &to_copy_to) {
	*this = to_copy_to;
}

template <class T>
queue_list<T>::~queue_list() {

}

template <class T>
void queue_list<T>::push_back(T n) {
	q.push_back(n);
	num++;
}

template <class T>
int queue_list<T>::front(T* top_element) {
	if (num == 0) {
		return -1;
	}
	*top_element = *q.begin();
	return 1;
}

template <class T>
void queue_list<T>::pop_front() {
	if (num > 0) {
		q.pop_front();
		num--;
	}
}

template <class T>
int queue_list<T>::size() {
	return num;
}