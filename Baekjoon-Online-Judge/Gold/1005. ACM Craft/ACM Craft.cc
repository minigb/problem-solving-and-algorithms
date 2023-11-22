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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	int N, K;
	int X, Y;
	int W;
	int i;

	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<ll> time(N + 5), time_needed(N + 5);
		for (i = 1; i <= N; i++) {
			cin >> time[i];
		}

		vector<vector<int>> nextis(N + 5);
		vector<int> cnt(N + 5, 0);
		while (K--) {
			cin >> X >> Y;
			nextis[X].push_back(Y);
			cnt[Y]++;
		}
		cin >> W;
		
		queue<int> que;
		for (i = 1; i <= N; i++) {
			if (cnt[i] == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			time[cur] += time_needed[cur];

			if (cur == W) {
				cout << time[cur] << '\n';
				break;
			}

			for (int next : nextis[cur]) {
				time_needed[next] = max(time_needed[next], time[cur]);
				if (--cnt[next] == 0) {
					que.push(next);
				}
			}
		}
	}

	return 0;
}