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

bool is_possible(const int room_limit, const int t, const vector<int>& arr) {
    const int n = arr.size();
    vector<int> min_possible_day(room_limit, 1);

    for (int i = 0; i < n; ++i) {
        int room_num = i % room_limit;
        int possible_start_day = max(arr[i] - t + 1, min_possible_day[room_num]);
        if (possible_start_day <= arr[i]) {
            min_possible_day[room_num] = possible_start_day + t;
        }
        else {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int left = 1, right = n + 1;
    int answer = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (is_possible(mid, t, arr)) {
            answer = mid;
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << answer << kEndl;
}