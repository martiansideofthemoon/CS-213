#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "mfile.hpp"
using namespace std;
int hashpjw(string s, int num) {
	char p;
	unsigned h =0, g;
	for (int i = 0; i < s.length(); i++) {
		h = (h << 4) + (s[i]);
		if (g = h&0xf0000000) {
			h = h ^ (g << 24);
			h = h ^ g;
		}
	}
	return h % num;
}
int main() {
	string file;
	cin >> file;
	int n;
	cin >> n;
	MFile f;
	f.init(file, n);
	int count = 0;
	string s = f.readNext();
	while(s.length() > 0) {
		count++;
		s = f.readNext();
	}
	f.close();
	MFile f2;
	f2.init(file, n);
	list<string> lines[count];
	s = f2.readNext();
	int unique = 0;
	while(s.length() > 0) {
		int index = hashpjw(s, count);
		if (lines[index].empty()) {
			unique++;
			lines[index].push_back(s);
		} else {
			list<string>::iterator a = lines[index].begin();
			bool match_found = false;
			while (a != lines[index].end()) {
				if (*a == s) {
					match_found = true;
					break;
				}
				a++;
			}
			if (!match_found) {
				unique++;
				lines[index].push_back(s);
			}
		}
		s = f2.readNext();
	}
	cout << unique << endl;
	f.close();
}