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

class FrequencyList {
private:
	list<Frame> frames;
	int frequency;
public:
	FrequencyList(f) {
		frequency = f;
	}

	void addFrame(Frame* f) {
		frames.push_back(*f);
	}

	void removeFrame(list<Frame>::iterator i) {
		frames.erase(i);
	}
};

int main() {
	int ids, frames, references;
	cin >> ids >> frames >> references;
	int current_frames = 0;
	list<FrequencyList> frequencies;
	list<FrequencyList>::iterator freq_list_position[]
	list<Frame>::iterator all_pages[ids];
	for (int i = 0; i < references; i++) {
		int page;
		cin >> page;
		if (all_pages[id] == NULL) {
			// Page not present in memory
		} else {
			// Page present in memory
			// Remove frame from old FrequencyList

			// Add frame to new FrequencyList
		}
	}
}