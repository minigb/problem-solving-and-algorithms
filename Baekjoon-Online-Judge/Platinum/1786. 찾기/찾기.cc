#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ENDL '\n'

class KMP {
public:
	string str, pat;
	vector<int> table;
	vector<int> ans;
		
	void getTable() {
		table.resize(pat.length());
		int left = 0;
		for (int i = 1; i < pat.length(); i++) {
			while (left > 0 && pat[left] != pat[i]) {
				left = table[left - 1];
			}
			if (pat[left] == pat[i]) {
				table[i] = left + 1;
				left++;
			}
		}
	}

	void getAns() {
		getTable();
		int patIdx = 0;
		for (int strIdx = 0; strIdx < str.length(); strIdx++) {
			while (patIdx > 0 && pat[patIdx] != str[strIdx]) {
				patIdx = table[patIdx - 1];
			}
			if (pat[patIdx] == str[strIdx]) {
				if (patIdx == pat.length() - 1) {
					ans.push_back(strIdx - pat.length() + 1);
					patIdx = table[patIdx];
				}
				else {
					patIdx++;
				}
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	KMP kmp;

	getline(cin, kmp.str);
	getline(cin, kmp.pat);

	kmp.getAns();

	cout << kmp.ans.size() << ENDL;
	for (int i : kmp.ans) {
		cout << i + 1 << ' ';
	}
	cout << ENDL;

	return 0;
}