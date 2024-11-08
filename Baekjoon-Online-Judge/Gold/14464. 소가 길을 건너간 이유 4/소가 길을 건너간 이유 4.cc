#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);
ll GCD(ll k, ll l) { return l ? GCD(l, k % l) : k; }

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int c, n; cin >> c >> n;
    vector<int> t(c);
    for (int i = 0; i < c; ++i) {
        cin >> t[i];
    }
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(t.begin(), t.end());
    sort(intervals.begin(), intervals.end());

    int answer = 0;

    priority_queue<int, vector<int>, greater<>> pq;
    int intervals_idx = 0;
    for (int cur_t : t) {
        for (; intervals_idx < n && intervals[intervals_idx].first <= cur_t; ++intervals_idx) {
            pq.push(intervals[intervals_idx].second);
        }

        while (!pq.empty() && !(cur_t <= pq.top())) {
            pq.pop();
        }

        if (!pq.empty()) {
            ++answer;
            pq.pop();
        }
    }

    cout << answer << kEndl;
}