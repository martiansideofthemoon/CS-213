#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <list>
using namespace std;
template<class T>
class stack {
private:
	// Add your member variables here
	list<T> elements;
	int num;
public:
	/**
	 * Default constructor for the stack class
	 */
	 stack();

	/**
	 * Copy constructor for the stack class.
	 * Params:
	 * const stack &to_copy_to : A reference to the stack object to be copied
	 * into.
	 */
	stack(const stack &to_copy_to);

	/**
	 * Default destructor for the stack class
	 */
	~stack();

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
	 * Returns the number of elements in the queue
	 * Return value:
	 * int : Number of elements in the queue
	 */
	int size();
};

#endif //_STACK_HPP_