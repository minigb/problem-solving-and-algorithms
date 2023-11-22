#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Posi {
	int x, y;
};

struct sortby {
	bool operator () (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int N;
vector<vector<pair<int, int>>> graph;
const int inf = 2000000000;

int dij(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M, X;
	int a, b, c;
	int ans;
	int i;

	cin >> N >> M >> X;
	graph.resize(N + 1);

	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	ans = 0;
	for (i = 1; i <= N; i++) {
		ans = max(ans, dij(i, X) + dij(X, i));
	}

	cout << ans << '\n';

	return 0;
}

int dij(int start, int end)
{
	vector<int> dist(N + 1, inf);
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, sortby> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int cur = pq.top().first;
		pq.pop();

		if (cur == end) {
			break;
		}

		for (pair<int, int> v : graph[cur]) {
			if (dist[v.first] > v.second + dist[cur]) {
				dist[v.first] = v.second + dist[cur];
				pq.push(make_pair(v.first, dist[v.first]));
			}
		}
	}

	return dist[end];
}