#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include "mfile.hpp"
using namespace std;
int main() {
	string file;
	cin >> file;
	int n;
	cin >> n;
	hash<std::string> str_hash;
	int unique = 0;
	MFile f;
	f.init(file, n);
	// The key is the hash of the string
	// The value is a vector of line numbers having this hash
	unordered_map< int, vector<int> > lines;
	string s = f.readNext();
	int line_no = -1;
	while(s.length() > 0) {
		line_no++;
		int k = str_hash(s);
		unordered_map< int, vector<int> >::iterator a1 = lines.find(k);
		if (a1 == lines.end()) {
			// Element hash doesn't exist! It's definitely unique!
			unique++;
			vector<int> a;
			a.push_back(line_no);
			lines.insert(pair<int, vector<int> >(k, a));
		} else {
			// Investigate strings of this hash
			vector<int> a = a1->second;
			bool string_found = false;
			vector<string> matches = f.readLines(a);
			vector<string>::iterator it = matches.begin();
			while (it != matches.end()) {
				if (s == *it) {
					string_found = true;
					break;
				}
				it++;
			}
			if (!string_found) {
				unique++;
				(a1->second).push_back(line_no);
			}
		}
		s = f.readNext();
	}
	cout << unique << endl;
	f.close();
}