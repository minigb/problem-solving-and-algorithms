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

vector<vector<ll>> height_map;
vector<vector<ll>> dp_table;
const ll INF = ll(2e15);

struct Position {
    int row, col;
    Position(int a, int b) {
        row = a; col = b;
    }
    Position operator+ (Position obj) {
        return Position(this->row + obj.row, this->col+obj.col);
    }
    bool operator== (Position two) {
        return (this->row == two.row && this->col ==  two.col);
    }
};

bool isValid(Position position) {
    return height_map[position.row][position.col] != -1;
}
bool isUpdated(Position position) {
    return dp_table[position.row][position.col] != INF;
}
ll getTableValue(const vector<vector<ll>>& table, const Position& k) {
    return table[k.row][k.col];
}

ll runDP(Position cur) {
    if (isUpdated(cur)) {
        return getTableValue(dp_table, cur);
    }
    
    vector<Position> dir_vec = {{0, -1}, {-1, 0}};
    for (Position dir : dir_vec) {
        Position prev_position = cur + dir;
        if (!isValid(prev_position)) {
            continue;
        }
        ll cost = max(0LL, getTableValue(height_map, cur) + 1 - getTableValue(height_map, prev_position));
        dp_table[cur.row][cur.col] = min(getTableValue(dp_table, cur), runDP(prev_position) + cost);
    }
    return getTableValue(dp_table, cur);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    height_map.resize(n + 1, vector<ll>(n + 1, -1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> height_map[i][j];
        }
    }

    dp_table.resize(n + 1, vector<ll>(n + 1, INF));
    dp_table[1][1] = 0;

    cout << runDP(Position(n, n)) << kEndl;

    return 0;
}