#include <list>
#include <iostream>
using namespace std;
class Frame {
private:
	int page_id;
	int frequency;
	int last_used;
public:
	Frame(int id) {
		page_id = id;
	}

	Frame(int id, int ref_no) {
		page_id = id;
		last_used = ref_no;
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
int main() {
	int ids, frames, references;
	cin >> ids >> frames >> references;
	Frame all_pages[frames];
}