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
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);

long long Solution(const vector<string>& input, const int n, const int k) {
	long long answer = 0;

	vector<int> count_name(21);
	for (int i = 0; i < n; ++i) {
		if (i - k - 1 >= 0) {
			--count_name[input[i - k - 1].length()];
		}
		if (i - 1 >= 0) {
			++count_name[input[i - 1].length()];
		}
		answer += count_name[input[i].length()];
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << Solution(arr, n, k);
}