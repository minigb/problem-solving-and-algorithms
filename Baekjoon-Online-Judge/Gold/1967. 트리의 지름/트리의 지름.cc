#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[10001];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int ans;
	int cur, sum, next;
	int a, b, c;
	int i, j;

	cin >> n;

	for (i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	ans = 0;
	for (i = 1; i <= n; i++) {
		queue<pair<int, int>> que;
		bool visited[10001]{};

		que.push(make_pair(i, 0));
		visited[i] = 1;

		while (!que.empty()) {
			cur = que.front().first;
			sum = que.front().second;
			ans = max(ans, sum);
			que.pop();

			for (j = 0; j < tree[cur].size(); j++) {
				next = tree[cur][j].first;
				if (!visited[next]) {
					visited[next] = 1;
					que.push(make_pair(next, sum + tree[cur][j].second));
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}