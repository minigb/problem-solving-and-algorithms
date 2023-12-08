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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n), b(n), x(n);
    vector<ll> diff(n), diff_divided(n);
    bool answer = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        diff[i] = abs(a[i] - b[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (diff[i] % x[i]) {
            answer = false;
            break;
        }
        diff_divided[i] = diff[i] / x[i];
        if (diff_divided[i] % 2 != diff_divided[0] % 2) {
            answer = false;
            break;
        }
    }

    if (!answer) {
        cout << -1 << kEndl;
    }
    else {
        cout << *max_element(diff_divided.begin(), diff_divided.end());
    }
}