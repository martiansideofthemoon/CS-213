#include <iostream>
#include "queue_list.cpp"

using namespace std;
int main() {
	queue_list<float> ab;
	float abc = 0;
	ab.push_back(6);
	ab.front(&abc);
	cout << abc << " ";
	ab.push_back(4);
	ab.front(&abc);
	cout << abc << " ";
	ab.push_back(7);
	ab.front(&abc);
	cout << abc << " ";
	ab.push_back(8.4);
	ab.front(&abc);
	cout << abc << " ";
	ab.pop_front();
	ab.front(&abc);
	cout << abc << " ";
	ab.pop_front();
	ab.front(&abc);
	cout << abc << " ";
	ab.pop_front();
	ab.front(&abc);
	cout << abc << " ";
	ab.pop_front();
	ab.front(&abc);
	cout << abc << " ";
	ab.pop_front();
	ab.front(&abc);
	cout << abc << endl;
	cout << ab.size() << endl;
	ab.push_back(2.3);
	cout << ab.size() << endl;
	ab.front(&abc);
	cout << abc << endl;
}