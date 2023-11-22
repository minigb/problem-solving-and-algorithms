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
#define ENDL '\n'
#define PI acos(-1)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> psum(n);
	for (int i = 1; i < n; i++) psum[i] = abs(arr[i] - arr[i - 1]) + psum[i - 1];

	while (q--) {
		int left, right; cin >> left >> right;
		left--; right--;

		int ans;
		if (left >= right) ans = 0;
		else ans = psum[right] - psum[left];

		cout << ans << ENDL;
	}
	return 0;
}