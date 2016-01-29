#include <iostream>
#include "stack.cpp"

using namespace std;
int main() {
	stack<float> ab;
	ab.push(6);
	ab.push(4);
	ab.push(7);
	ab.push(8.4);
	float abc = 0;
	ab.top(&abc);
	cout << abc << " ";
	ab.pop();
	ab.top(&abc);
	cout << abc << " ";
	ab.pop();
	ab.top(&abc);
	cout << abc << " ";
	ab.pop();
	ab.top(&abc);
	cout << abc << " ";
	ab.pop();
	ab.top(&abc);
	cout << abc << " ";
	ab.pop();
	ab.top(&abc);
	cout << abc << endl;
	cout << ab.size() << endl;
	ab.push(2.3);
	cout << ab.size() << endl;
	ab.top(&abc);
	cout << abc << endl;
}