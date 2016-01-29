#include <iostream>
#include <string>
#include <stack>
using namespace std;

class operation {
private:
	int op_type;
	string* op_text;
	int op_length;
public:
	operation() {
		op_type = -1;
		op_text = new string("");
		op_length = -1;
	}
	operation(int type, string &t) {
		op_type = type;
		op_text = new string(t);
		op_length = op_text->length();
	}
	operation(const operation& op) {
		*this = op;
	}
	int getType() {
		return op_type;
	}
	int getLength() {
		return op_length;
	}
	string getText() {
		return *op_text;
	}
};

class editor {
private:
	string* a;
	stack<operation> history;
	stack<operation> undo_history;
public:
	editor() {
		a = new string("");
	}

	void append(string w, int normal) {
		a->append(w);
		if (normal == 1) {
			operation* s = new operation(0, w);
			history.push(*s);
			undo_history = stack<operation>();
		}
	}

	void erase(int k, int normal) {
		string w = a->substr(a->length() - k, k);
		a->erase(a->length() - k, k);
		if (normal == 1) {
			operation* s = new operation(1, w);
			history.push(*s);
			undo_history = stack<operation>();
		}
	}

	char get(int k) {
		if (k > a->length()) {
			return ' ';
		}
		return (*a)[k];
	}

	void undo() {
		if (!history.empty()) {
			operation a = history.top();
			if (a.getType() == 0) {
				erase(a.getLength(), 0);
			} else {
				append(a.getText(), 0);
			}
			undo_history.push(a);
			history.pop();
		}
	}

	void redo() {
		if (!undo_history.empty()) {
			operation a = undo_history.top();
			undo_history.pop();
				if (a.getType() == 0) {
					append(a.getText(), 0);
				} else {
					erase(a.getLength(), 0);
				}
			history.push(a);
		}
	}
};

int main() {
	editor e;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		char a;
		cin >> a;
		if (a == 'a') {
			string s;
			cin >> s;
			e.append(s, 1);
		} else if (a == 'e') {
			int k;
			cin >> k;
			e.erase(k, 1);
		} else if (a == 'g') {
			int m;
			cin >> m;
			cout << e.get(m) << endl;
		} else if (a == 'u') {
			e.undo();
		} else if (a == 'r') {
			e.redo();
		}
	}
}