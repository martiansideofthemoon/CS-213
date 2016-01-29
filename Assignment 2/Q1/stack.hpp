#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <list>
using namespace std;
template<class T>
class stack {
private:
	// Add your member variables here
	list<T> elements;
	int num = 0;
public:

	/**
	 * Pushes an object of type T on the top of the stack
	 * Params:
	 * T n : The object to be pushed on the top of the stack
	 */
	void push(T n);


	/**
	 * Gives the element on the top of the stack, if any
	 * Params:
	 * T *top_element : Pointer to the location where the top element is to be
	 *                  stored before returning
	 * Return value:
	 * int : Positive if stack is non empty, negative if it is empty
	 */
	int top(T *top_element);

	/**
	 * Removes the element on the top of the stack, if any
	 */
	void pop();

	/**
	 * Returns the number of elements in the stack
	 * Return value:
	 * int : Number of elements in the stack
	 */
	int size();
};

#endif //_STACK_HPP_