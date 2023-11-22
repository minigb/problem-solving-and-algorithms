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

void GetPossibleSum(const vector<int>& arr, map<int, int>& count) {
    int n = arr.size();
    if (n == 0) {
        return;
    }

    vector<int> p_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        p_sum[i] = p_sum[i - 1] + arr[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) { //[i, j]
            int sum = p_sum[j] - p_sum[i - 1];
            ++count[sum];
        }
    }
}

long long Solution(const vector<int>& arr_a, const vector<int>& arr_b, const int t) {
    map<int, int> count_a, count_b;
    GetPossibleSum(arr_a, count_a);
    GetPossibleSum(arr_b, count_b);

    long long answer = 0;
    for (auto iter = count_a.begin(); iter != count_a.end(); ++iter) {
        auto iter_b = count_b.find(t - iter->first);
        if (iter_b != count_b.end()) {
            answer += (long long)iter->second * iter_b->second;
        }
    }

    return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    cout << Solution(a, b, t) << kEndl;
}