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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	int cur_time = 0;
	for (int i = 0; i < n; ++i) {
		int cross, bridge, green, red;
		cin >> cross >> bridge >> green >> red;
		int wait_till_green = cur_time % (green + red);
		if (wait_till_green < green) {
			wait_till_green = 0;
		}
		else {
			wait_till_green = green + red - wait_till_green;
		}

		cur_time += min(wait_till_green + cross, bridge);
	}

	cout << cur_time << kEndl;
}