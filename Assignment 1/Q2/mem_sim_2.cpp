#include <list>
#include <iostream>
using namespace std;
void print_list(list<int> i) {
	cout << "List: " << endl;
	list<int>::iterator c = i.begin();
	while(c != i.end()) {
		cout << *c << " ";
		c++;
	}
	cout << endl;
}

void print_list(list< list<int>* > i) {
	cout << "List: " << endl;
	list< list<int>* >::iterator c = i.begin();
	while(c != i.end()) {
		list<int>::iterator a = (**c).begin();
		while (a != (**c).end()) {
			cout << *a << " ";
			a++;
		}
		c++;
		cout << endl;
	}
	cout << "End List" << endl;
}
class memory {
private:
	list< list<int>* > current_pages;
	list< list<int>* >::iterator* freq_ptrs;
	list<int>::iterator* page_ptrs;
	int* page_frequency;
	int frame_limit;
	int size;
public:
	memory(int pages, int frames, int references) {
		freq_ptrs = new list< list<int>* >::iterator[references + 1];
		page_ptrs = new list<int>::iterator[pages + 1];
		page_frequency = new int[pages + 1];
		for (int i = 0; i < pages; i++) {
			page_frequency[i] = 0;
		}
		for (int i = 0; i < references; i++) {
			freq_ptrs[i] = current_pages.end();
		}
		size = 0;
		frame_limit = frames;
	}

	char forward(int page) {
		char forward = 'm';
		if (page_frequency[page] == 0) {
			// This page is not in memory yet
			if (size >= frame_limit) {
				// We need to pop least frequently used element, with oldest last used.
				size--;
				list<int>::iterator abc = (**(current_pages.begin())).end();
				abc--;
				(**(current_pages.begin())).erase(abc);
				if ((**(current_pages.begin())).begin() == (**(current_pages.begin())).end()) {
					current_pages.erase(current_pages.begin());
					freq_ptrs[page_frequency[*abc]] = current_pages.end();
				}
				page_frequency[*abc] = 0;
			}
			// Insert the page normally
			list< list<int>* >::iterator single_freq = freq_ptrs[1];
			if (single_freq == current_pages.end()) {
				// Frequency entry not yet there
				list<int>* l1 = new list<int>;
				(*l1).insert((*l1).begin(), page);
				freq_ptrs[1] = current_pages.insert(current_pages.begin(), l1);
				page_ptrs[page] = (**(freq_ptrs[1])).begin();
				//print_list(**(freq_ptrs[1]));
				page_frequency[page] = 1;
			} else {
				// Frequency entry is present
				page_ptrs[page] = (**single_freq).insert((**single_freq).begin(), page);
				page_frequency[page] = 1;
			}
			size++;
		} else {
			forward = 'h';
			list< list<int>* >::iterator freq_pointer = freq_ptrs[page_frequency[page]];
			list<int>::iterator page_ptr = page_ptrs[page];
			(**freq_pointer).erase(page_ptr);
			if ((**freq_pointer).begin() == (**freq_pointer).end()) {
				current_pages.erase(freq_pointer);
				freq_ptrs[page_frequency[page]] = current_pages.end();
			}
			if (freq_ptrs[page_frequency[page] + 1] == current_pages.end()) {
				// Frequency doesn't exist!
				list<int>* l1 = new list<int>;
				page_ptrs[page] = (*l1).insert((*l1).begin(), page);
				freq_pointer++;
				freq_ptrs[page_frequency[page] + 1] = current_pages.insert(freq_pointer, l1);
			} else {
				freq_pointer = freq_ptrs[page_frequency[page] + 1];
				page_ptrs[page] = (**freq_pointer).insert((**freq_pointer).begin(), page);
			}
			page_frequency[page]++;
		}
		return forward;
	}
};
int main() {
	int n,p,m;
	int hits = 0;
	int misses = 0;
	cin >> n >> p >> m;
	memory m1(n, p, m);
	for (int i = 0; i < m; i++) {
		//cout << i << endl;
		int page;
		cin >> page;
		char result = m1.forward(page);
		if (result == 'h') {
			hits++;
		} else {
			misses++;
		}
	}
	cout << hits << endl;
	cout << misses << endl;
}