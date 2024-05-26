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
ll INF = 1e18;

ll get_diff(pair<ll, ll> from, pair<ll, ll> to) {
	ll need = abs(from.first - to.first) + abs(from.second - to.second);
	return need;
}

pair<ll, ll> get_sum(pair<ll, ll> from, pair<ll, ll> to) {
	return { from.first + to.first, from.second + to.second };
}

pair<ll, ll> subtract(pair<ll, ll> a, pair<ll, ll> b) {
	return { a.first - b.first, a.second - b.second };
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k; cin >> n >> k;
	vector<pair<ll, ll>> items(n);
	for (ll i = 0; i < n; ++i) {
		cin >> items[i].first >> items[i].second;
	}
	sort(items.begin(), items.end());

	ll ex, ey; cin >> ex >> ey;
	pair<ll, ll> end = { ex, ey };
	
	ll answer = INF;

	// no item
	ll diff = get_diff({ 0, 0 }, end);
	if (diff <= k) {
		answer = min(answer, diff);
	}

	// one item
	if (k >= 2) {
		ll min_diff = INF;
		for (const pair<ll, ll>& item : items) {
			min_diff = min(min_diff, get_diff(item, end));
		}
		if (min_diff + 2 <= k) {
			answer = min(answer, 2 + min_diff);
		}
	}

	// two items, no move
	if (k >= 4) {
		for (int i = 0; i < n; ++i) {
			pair<ll, ll> need = subtract(end, items[i]);
			// cout << need.first << ' ' << need.second << kEndl;

			if (binary_search(items.begin(), items.end(), need)) {
				// int idx = upper_bound(items.begin(), items.end(), need) - lower_bound(items.begin(), items.end(), need);
				// cout << i << ' ' << idx << kEndl;
				answer = min(answer, (ll)4);
			}
		}
	}

	// two items, one move
	if (k == 5) {
		vector<pair<ll, ll>> add_vec = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		for (int i = 0; i< n; ++i) {
			for (auto add : add_vec) {
				pair<ll, ll> need = get_sum(subtract({ ex, ey }, items[i]), add);

				if (binary_search(items.begin(), items.end(), need)) {
					// int idx = upper_bound(items.begin(), items.end(), need) - lower_bound(items.begin(), items.end(), need);
					// cout << i << ' ' << idx << kEndl;
					answer = min(answer, (ll)5);
				}
			}
		}
	}
	
	if (answer == INF) {
		cout << -1 << kEndl;
	}
	else {
		cout << answer << kEndl;
	}
}