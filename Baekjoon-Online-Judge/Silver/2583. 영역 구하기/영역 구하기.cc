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
	int M, N, K;
	int x1, y1, x2, y2;
	int cnt;
	vector<int> ans;
	int diry[4] = { -1, 1, 0, 0 }, dirx[4] = { 0, 0, -1, 1 };
	int i, j, k;

	cin >> M >> N >> K;
	vector<vector<int>> arr(M + 5, vector<int>(N + 5, 0)); //0: 덮힘, 1: 안 덮힘
	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			arr[i][j] = 1;
		}
	}

	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = y1 + 1; i <= y2; i++) {
			for (j = x1 + 1; j <= x2; j++) {
				arr[i][j] = 0;
			}
		}
	}

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			if (arr[i][j] == 1) {
				cnt = 1;
				queue<pair<int, int>> que;
				que.push({ i, j });
				arr[i][j] = 0;

				while (!que.empty()) {
					int y = que.front().first;
					int x = que.front().second;
					que.pop();

					for (k = 0; k < 4; k++) {
						int yy = y + diry[k];
						int xx = x + dirx[k];

						if (arr[yy][xx] == 1) {
							cnt++;
							que.push({ yy, xx });
							arr[yy][xx] = 0;
						}
					}
				}

				ans.push_back(cnt);
			}
		}
	}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int cur : ans) {
		cout << cur << ' ';
	}
	cout << '\n';

	return 0;
}