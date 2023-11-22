#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj(10001);
vector<vector<int>> level(10001);
vector<int> order(10001);
int cnt;

void inorder(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	bool findRoot[10001]{};
	int rootNode;
	bool visited[10001]{};
	int a, b, c;
	int cur, depth, maxDepth;
	int len, ans, ansLevel;
	int i;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;
		adj[a].first = b;
		adj[a].second = c;
		if (b != -1) {
			findRoot[b] = 1;
		}
		if (c != -1) {
			findRoot[c] = 1;
		}
	}

	for (i = 1; i <= n; i++) {
		if (findRoot[i] == 0) {
			rootNode = i;
			break;
		}
	}

	queue<pair<int, int>> que;
	que.push(make_pair(rootNode, 1));
	visited[rootNode] = 1;
	maxDepth = 0;
	while (!que.empty()) {
		cur = que.front().first;
		depth = que.front().second;
		maxDepth = max(depth, maxDepth);
		que.pop();

		level[depth].push_back(cur);

		if (adj[cur].first != -1) {
			que.push(make_pair(adj[cur].first, depth + 1));
		}
		if (adj[cur].second != -1) {
			que.push(make_pair(adj[cur].second, depth + 1));
		}
	}

	cnt = 0;
	inorder(rootNode);

	ans = 1;
	ansLevel = 1;
	for (i = 1; i <= maxDepth; i++) {
		len = order[*(level[i].end() - 1)] - order[*level[i].begin()] + 1;
		if (ans < len) {
			ans = len;
			ansLevel = i;
		}
	}

	cout << ansLevel << ' ' << ans << '\n';


	return 0;
}

void inorder(int curNode)
{
	if (adj[curNode].first > 0) {
		inorder(adj[curNode].first);
	}
	order[curNode] = ++cnt;
	if (adj[curNode].second > 0) {
		inorder(adj[curNode].second);
	}

	return;
}