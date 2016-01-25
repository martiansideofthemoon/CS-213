#include <list>
#include <iostream>
using namespace std;
class Frame {
private:
	int page_id;
	int frequency;
	int last_used;
public:
	Frame() {
		page_id = -1;
		last_used = -1;
		frequency = 0;
	}

	Frame(int id) {
		page_id = id;
		last_used = -1;
		frequency = 0;
	}

	Frame(int id, int ref_no) {
		page_id = id;
		last_used = ref_no;
		frequency = 0;
	}

	int getPageId() {
		return page_id;
	}

	int getFrequency() {
		return frequency;
	}

	int getLastUsed() {
		return last_used;
	}

	void increment(int ref_no) {
		frequency += 1;
		last_used = ref_no;
	}

	void reset() {
		frequency = 0;
	}
};
void print_list(list<Frame> &f) {
	list<Frame>::iterator a = f.begin();
	while (a != f.end()) {
		cout << a->getPageId() << " - ";
		a++;
	}
	cout << endl;
}
int main() {
	int page_max, num_frames, references;
	cin >> page_max >> num_frames >> references;
	list<Frame> frames;
	int size = 0;
	int hits = 0, misses = 0;
	for (int i = 0; i < references; i++) {
		//if (i%10000 == 0)
		//	cout << i << endl;
		int page;
		cin >> page;
		list<Frame>::iterator least_frequent_page = frames.end();
		list<Frame>::iterator x = frames.begin();
		bool pageFound = false;
		bool lru_used = false;
		while (x != frames.end()) {
			if (size > 0 && (least_frequent_page == frames.end() || x->getFrequency() <= least_frequent_page->getFrequency())) {
				if (least_frequent_page == frames.end()) {
					least_frequent_page = x;
				} else if (x->getFrequency() < least_frequent_page->getFrequency()) {
					least_frequent_page = x;
				} else if (x->getLastUsed() < least_frequent_page->getLastUsed()) {
					least_frequent_page = x;
				}
			}
			if (x->getPageId() == page) {
				x->increment(i);
				pageFound = true;
				hits++;
				break;
			}
			x++;
		}
		if (!pageFound) {
			misses++;
			if (size < num_frames) {
				size++;
				Frame* f = new Frame(page, i);
				frames.push_back(*f);
			} else {
				//cout << "Least frequent page is " << least_frequent_page->getPageId() << endl;
				frames.erase(least_frequent_page);
				Frame* f = new Frame(page, i);
				frames.push_back(*f);
			}
		}
	}
	cout << hits << endl;
	cout << misses << endl;
}