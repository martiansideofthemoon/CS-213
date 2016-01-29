#include "queue_vector.hpp"
using namespace std;

template <class T>
queue_vector<T>::queue_vector() {
	num = 0;
}

template <class T>
queue_vector<T>::queue_vector(const queue_vector &to_copy_to) {
	*this = to_copy_to;
}

template <class T>
queue_vector<T>::~queue_vector() {

}

template <class T>
void queue_vector<T>::push_back(T n) {
	v.push_back(n);
	num++;
}

template <class T>
int queue_vector<T>::front(T* top_element) {
	if (num == 0) {
		return -1;
	}
	*top_element = *v.begin();
	return 1;
}

template <class T>
void queue_vector<T>::pop_front() {
	if (num > 0) {
		v.erase(v.begin());
		num--;
	}
}

template <class T>
int queue_vector<T>::size() {
	return num;
}