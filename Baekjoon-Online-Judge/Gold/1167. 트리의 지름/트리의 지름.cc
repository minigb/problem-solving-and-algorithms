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

vector<vector<pair<int, ll>>> adj;
vector<bool> chk;
int start, last;
ll max_;

void dfs(int, ll);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int V;
	int a, b;
	ll c;
	int i;

	cin >> V;
	adj.resize(V + 5);
	for (i = 1; i <= V; i++) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) {
				break;
			}
			cin >> c;
			adj[a].push_back({ b, c });
		}
	}

	chk.resize(V + 5, false);
	start = 1;
	chk[start] = true;
	max_ = 0;
	dfs(1, 0);

	chk.clear();
	chk.resize(V + 5, false);
	start = last;
	max_ = 0;
	chk[start] = true;
	dfs(start, 0);

	cout << max_ << '\n';

	return 0;
}

void dfs(int cur, ll len)
{
	if (max_ < len) {
		max_ = len;
		last = cur;
	}

	for (pair<int, ll> next : adj[cur]) {
		if (chk[next.first] == false) {
			chk[next.first] = true;
			dfs(next.first, len + next.second);
			chk[next.first] = false;
		}
	}
}