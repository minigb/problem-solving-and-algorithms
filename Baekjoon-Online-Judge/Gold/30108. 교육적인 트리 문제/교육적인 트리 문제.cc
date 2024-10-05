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

    int n; cin >> n;
    vector<vector<int>> childs(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        childs[p].push_back(i);
    }
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    priority_queue<pair<int, int>> pq; // <weight, idx>
    // childs[0].push_back(1);
    // pq.push({0, 0});
    pq.push({arr[1], 1});

    ll sum = 0;
    // vector<ll> ans;
    for (int i = 1; i <= n; ++i) {
        auto top_elem = pq.top();
        pq.pop();

        int val = top_elem.first;
        int node = top_elem.second;

        sum += val;
        cout << sum << kEndl;

        for (auto child : childs[node]) {
            pq.push({arr[child], child});
        }
    }
}