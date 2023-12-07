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

// int dp[13][13][10001];
const int MAX = 2e9;
vector<vector<vector<int>>> dp(13, vector<vector<int>>(13, vector<int>(10001, MAX)));

int dist(int a, int b) {
    if (a == b) {
        return 0;
    }
    if (a > b) {
        swap(a, b);
    }
    pair<int, int> new_a = {(a - 1) / 3, (a - 1) % 3};
    pair<int, int> new_b = {(b - 1) / 3, (b - 1) % 3};
    return abs(new_a.first - new_b.first) + abs(new_a.second - new_b.second);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    dp[1][3][0] = 0;

    for (int cur = 1; cur <= n; ++cur) {
        int next; cin >> next;

        for (int i = 1; i <= 12; ++i) {
            for (int j = 1; j <= 12; ++j) {
                if (dp[i][j][cur - 1] != MAX) {
                    dp[next][j][cur] = min(dp[i][j][cur - 1] + dist(i, next) + a, dp[next][j][cur]);
                    dp[i][next][cur] = min(dp[i][j][cur - 1] + dist(j, next) + b, dp[i][next][cur]);
                }
            }
        }
    }

    int ans = MAX;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= 12; ++j) {
            ans = min(ans, dp[i][j][n]);
        }
    }
    cout << ans << kEndl;
}