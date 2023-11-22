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
#include <unordered_set>
#include <map>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);

long long Solution(const int n, const vector<vector<pair<int, long long>>> graph, const int start, const int end) {
    long long max_c = 0;
    for (int i = 1; i <= n; ++i) {
        for (const pair<int, long long>& next : graph[i]) {
            max_c = max(max_c, next.second);
        }
    }

    long long answer = 0;
    long long left = 1, right = max_c + 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        vector<bool> visited(n + 5, false);
        queue<int> que;
        que.push(start);
        visited[start] = true;
        long long min_c = 1e18;
        bool possible = false;

        while (!que.empty()) { 
            const int current = que.front();
            que.pop();

            if (current == end) {
                possible = true;
            }

            for (const pair<int, long long>& next : graph[current]) {
                if (visited[next.first] || next.second < mid) {
                    continue;
                }
                visited[next.first] = true;
                min_c = min(min_c, next.second);
                que.push(next.first);
            }
        }

        if (possible) {
            answer = min_c;
            left = min_c + 1;
        }
        else {
            right = mid;
        }
    }

    return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n + 1);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        graph[u].push_back({ v, c });
        graph[v].push_back({ u, c });
    }
    int s, e; cin >> s >> e;

    cout << Solution(n, graph, s, e);
}