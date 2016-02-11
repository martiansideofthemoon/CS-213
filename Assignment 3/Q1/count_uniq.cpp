#include <iostream>
#include <string>
#include <unordered_set>
#include "mfile.hpp"
#include <functional>
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
	unordered_set<long> lines;
	string s = f.readNext();
	long k = str_hash(s);
	while(s.length() > 0) {
		k = str_hash(s);
		unordered_set<long>::iterator a = lines.find(k);
		if (a == lines.end()) {
			unique++;
			lines.insert(k);
		}
		s = f.readNext();
	}
	cout << unique << endl;
	f.close();
}