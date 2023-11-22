#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);
ll GCD(ll k, ll l) { return l ? GCD(l, k % l) : k; }

struct Line {
	long long start, end;
	bool operator<(Line comp) {
		if (start == comp.start) {
			return end < comp.end;
		}
		return start < comp.start;
	}
};

long long GetLineLength(const Line& line) {
	return line.end - line.start;
}

long long Solution(const int& n, vector<Line>& line_vector) {
	for (Line& line : line_vector) {
		if (line.start > line.end) {
			swap(line.start, line.end);
		}
	}
	sort(line_vector.begin(), line_vector.end());

	Line current = line_vector[0];
	long long answer = GetLineLength(current);
	for (int i = 1; i < line_vector.size(); ++i) {
		const Line& new_line = line_vector[i];
		if (new_line.start <= current.end) {
			answer -= GetLineLength(current);
			current.end = max(current.end, new_line.end);
			answer += GetLineLength(current);
		}
		else {
			current = new_line;
			answer += GetLineLength(current);
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<Line> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].start >> arr[i].end;
	}
	cout << Solution(n, arr) << kEndl;
}