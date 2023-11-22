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
#include <map>
#include <iomanip>
#include <climits>
#include <cassert>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ENDL '\n'
#define PI acos(-1)
const int INF = 1e9;

int N;
vector<vector<int>> adj;
vector<bool> used;
vector<int> A, B;
vector<int> dist;
vector<int> see;

void Init()
{
	adj.clear(); adj.resize(N + 5);
	used.clear(); used.resize(N + 5);
	A.clear(); A.resize(N + 5, -1);
	B.clear(); B.resize(N + 5, -1);
	dist.clear(); dist.resize(N + 5, INF);
	see.clear(); see.resize(N + 5);
}

int cntBfs = 0, cntDfs = 0;

void Bfs() {
	//assert(++cntBfs < INF);
	queue<int> que;
	for (int i = 0; i < N; i++) {
		if (A[i] == -1) {
			dist[i] = 0;
			que.push(i);
		}
		else {
			dist[i] = INF;
		}
	}

	while (!que.empty()) {
		int cur = que.front(); que.pop();
		for (int next : adj[cur]) {
			if (B[next] != -1 && dist[B[next]] == INF) {
				dist[B[next]] = dist[cur] + 1;
				que.push(B[next]);
			}
		}
	}
}

bool Dfs(int cur) {
	//assert(++cntDfs < INF);
	for (int& i = see[cur]; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (B[next] == -1 || (dist[B[next]] == dist[cur] + 1 && Dfs(B[next]))) {
			A[cur] = next;
			B[next] = cur;
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int N;
	char trash;

	while (cin >> N) {
		Init();
		for (int i = 0; i < N; i++) {
			int k; cin >> k;
			cin >> trash; cin >> trash;
			int q; cin >> q;
			cin >> trash;
			while (q--) {
				int input; cin >> input;
				adj[k].push_back(input - N);
			}
		}

		int ans = 0;
		while (1) {
			see.clear(); see.resize(N + 5, 0);
			Bfs();
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (A[i] == -1 && Dfs(i)) {
					cnt++;
				}
			}

			if (cnt == 0) break;
			ans += cnt;
		}

		cout << ans << ENDL;
	}
	return 0;
}