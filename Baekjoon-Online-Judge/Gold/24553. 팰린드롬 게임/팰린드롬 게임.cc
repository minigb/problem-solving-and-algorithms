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

    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        cout << (int)(!(n % 10)) << kEndl;
    }
    
}