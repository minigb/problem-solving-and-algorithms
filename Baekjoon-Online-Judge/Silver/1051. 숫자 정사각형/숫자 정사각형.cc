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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c; cin >> c;
			arr[i][j] = c - '0';
		}
	}

	int ans = 1;
	for (int len = 2; len <= min(n, m); ++len) {
		for (int row = 0; row + len - 1 < n; ++row) {
			for (int col = 0; col + len - 1 < m; ++col) {
				int a = arr[row][col];
				int b = arr[row + len - 1][col];
				int c = arr[row][col + len - 1];
				int d = arr[row + len - 1][col + len - 1];
				if(a == b && b == c && c == d) {
					ans = max(ans, len * len);
				}
			}
		}
	}
	

	cout << ans << kEndl;
}