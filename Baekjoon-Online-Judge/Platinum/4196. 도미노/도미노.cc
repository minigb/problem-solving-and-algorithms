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
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음
//공백 포함해서 문자열 받기: getline(cin, s);

vector<vector<int>> adj;
vector<int> discover, scc;
stack<int> stck;
int cntAll, order;
int ans;

void init(int);
int SCC(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	int N, M;
	int x, y;
	int i;

	cin >> T;
	while (T--) {
		cin >> N >> M;
		init(N);

		while (M--) {
			cin >> x >> y;
			adj[x].push_back(y);
		}

		for (i = 1; i <= N; i++) {
			if (discover[i] == -1) {
				SCC(i);
			}
		}

		vector<bool> isStart(cntAll + 5, true);
		for (i = 1; i <= N; i++) {
			for (int next : adj[i]) {
				if (scc[i] != scc[next]) {
					isStart[scc[next]] = false;
				}
			}
		}

		ans = 0;
		for (i = 0; i < cntAll; i++) {
			if (isStart[i]) {
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

int SCC(int cur)
{
	int ret = discover[cur] = order++;
	stck.push(cur);

	for (int next : adj[cur]) {
		if (discover[next] == -1) {
			ret = min(ret, SCC(next));
		}
		else if (scc[next] == -1) {
			ret = min(ret, discover[next]);
		}
	}

	if (ret == discover[cur]) {
		while (1) {
			int temp = stck.top();
			stck.pop();

			scc[temp] = cntAll;

			if (temp == cur) {
				break;
			}
		}
		cntAll++;
	}

	return ret;
}

void init(int N)
{
	adj.clear();
	adj.resize(N + 5);

	discover.clear();
	discover.resize(N + 5, -1);

	scc.clear();
	scc.resize(N + 5, -1);

	while (!stck.empty()) {
		stck.pop();
	}

	cntAll = order = 0;
}