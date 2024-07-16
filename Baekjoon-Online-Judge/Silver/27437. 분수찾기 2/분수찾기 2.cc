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

ll sumThroughN(ll n) {
    if (n % 2 == 0) {
        return n / 2 * (n + 1);
    }
    else {
        return (n + 1) / 2 * n;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x; cin >> x;

    // find n
    // 1 + ... + n = n * (n + 1) / 2 >= x
    ll left = 1, right = ll(1.5e9);
    ll n = -1;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (sumThroughN(mid) >= x) {
            n = mid;
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    // print the answer
    ll k = x - sumThroughN(n - 1);
    ll numer = -1, denom = -1;
    if (n % 2 == 0) {
        // even
        // start from the top-right corner
        numer = 1 + k - 1;
    }
    else {
        numer = n - (k - 1);
    }
    denom = (n + 1) - numer;

    cout << numer << '/' << denom << '\n';
}