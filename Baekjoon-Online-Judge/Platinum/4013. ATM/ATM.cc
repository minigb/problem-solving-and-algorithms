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
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력: cout << fixed << setprecision(10) << ans << '\n'
//공백 포함해서 문자열 받기: getline(cin, s);

int dfs(int);

int cnt, cnt_all;
vector<vector<int>> fwd;
vector<int> discover, scc;
stack<int> stck;
vector<int> cash;
vector<int> scc_sum;

vector<vector<int>> adj;
vector<int> dp;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int x, y;
	int S, P;
	int ans;
	int i;

	cin >> N >> M;

	fwd.resize(N + 5);
	while (M--) {
		cin >> x >> y;
		fwd[x].push_back(y);
	}
	
	cash.resize(N + 5);
	for (i = 1; i <= N; i++) {
		cin >> cash[i];
	}

	discover.resize(N + 5, -1);
	scc.resize(N + 5, -1);
	cnt = cnt_all = 0;

	for (i = 1; i <= N; i++) {
		if (discover[i] == -1) {
			dfs(i);
		}
	}


	//최댓값 구하기
	adj.resize(cnt_all + 5);
	for (i = 1; i <= N; i++) {
		for (int next : fwd[i]) {
			if (scc[next] != scc[i]) {
				adj[scc[i]].push_back(scc[next]);
			}
		}
	}

	cin >> S;

	vector<int> visited(cnt_all + 5, false);
	vector<int> tro_cnt(cnt_all + 5, 0);
	queue<int> que;
	visited[scc[S]] = true;
	que.push(scc[S]);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int next : adj[cur]) {
			tro_cnt[next]++;
			if (!visited[next]) {
				visited[next] = true;
				que.push(next);
			}
		}
	}

	dp.resize(cnt_all + 5, 0);
	que.push(scc[S]);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		dp[cur] += scc_sum[cur];

		for (int next : adj[cur]) {
			dp[next] = max(dp[next], dp[cur]);
			if (--tro_cnt[next] == 0) {
				que.push(next);
			}
		}
	}

	ans = 0;
	cin >> P;
	while (P--) {
		cin >> x;
		ans = max(ans, dp[scc[x]]);
	}

	cout << ans << '\n';

	return 0;
}

int dfs(int cur)
{
	int ret = discover[cur] = cnt++;
	stck.push(cur);

	for (int next : fwd[cur]) {
		if (discover[next] == -1) {
			ret = min(ret, dfs(next));
		}
		else if (scc[next] == -1) {
			ret = min(ret, discover[next]);
		}
	}

	if (ret == discover[cur]) {
		scc_sum.push_back(0);
		while (!stck.empty()) {
			int temp = stck.top();
			stck.pop();

			scc[temp] = cnt_all;
			scc_sum[cnt_all] += cash[temp];

			if (temp == cur) {
				break;
			}
		}
		cnt_all++;
	}

	return ret;
}