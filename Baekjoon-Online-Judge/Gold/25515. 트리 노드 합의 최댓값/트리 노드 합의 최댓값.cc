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

const int ROOT = 0;
vector<vector<int>> child_vec;
vector<int> weight_vec;
vector<ll> max_sum_vec;

ll getMaxSum(int cur_root) {
    max_sum_vec[cur_root] = weight_vec[cur_root];
    for (int child : child_vec[cur_root]) {
        max_sum_vec[cur_root] += max(ll(0), getMaxSum(child));
    }
    return max_sum_vec[cur_root];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    child_vec.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        child_vec[a].push_back(b);
    }
    weight_vec.resize(n);
    for (int& weight : weight_vec) {
        cin >> weight;
    }

    max_sum_vec.resize(n, LLONG_MIN);
    cout << getMaxSum(ROOT) << kEndl;

    return 0;
}