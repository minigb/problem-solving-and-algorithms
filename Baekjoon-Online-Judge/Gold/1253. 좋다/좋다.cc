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

int Solution(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	int answer = 0;
	for (int i = 0; i < arr.size(); ++i) {
		int left = 0, right = arr.size() - 1;
		while (left < right) {
			if (left == i) {
				++left;
				continue;
			}
			if (right == i) {
				--right;
				continue;
			}
			int sum = arr[left] + arr[right];
			if (sum == arr[i]) {
				++answer;
				break;
			}
			else if (sum < arr[i]) {
				++left;
			}
			else {
				--right;
			}
		}
	}

	return answer;
}

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << Solution(arr) << kEndl;
}