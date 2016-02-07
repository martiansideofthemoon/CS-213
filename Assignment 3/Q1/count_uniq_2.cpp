#include <iostream>
#include <string>
#include <set>
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
	set<string> lines;
	string s = f.readNext();
	while(s.length() > 0) {
		set<string>::iterator a = lines.find(s);
		if (a == lines.end()) {
			count++;
			lines.insert(s);
		}
		s = f.readNext();
	}
	cout << count << endl;
	f.close();
}