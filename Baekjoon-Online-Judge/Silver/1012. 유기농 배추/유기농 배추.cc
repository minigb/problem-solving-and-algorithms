#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	int m, n, k;
	int arr[52][52];
	queue<pair<int, int>> que;
	int cnt;
	int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	int a, b;
	int i, j, i2, j2, s, u;

	cin >> t;
	for (s = 0; s < t; s++) {
		cin >> m >> n >> k;

		for (i = 0; i <= n + 1; i++) {
			for (j = 0; j <= m + 1; j++) {
				arr[i][j] = 0;
			}
		}

		for (i = 0; i < k; i++) {
			cin >> a >> b;
			arr[b + 1][a + 1] = 1;
		}

		cnt = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					que.push(make_pair(i, j));

					while (!que.empty()) {
						i2 = que.front().first;
						j2 = que.front().second;
						que.pop();

						for (u = 0; u < 4; u++) {
							if (arr[i2 + dir[u][0]][j2 + dir[u][1]] == 1) {
								arr[i2 + dir[u][0]][j2 + dir[u][1]] = 0;
								que.push(make_pair(i2 + dir[u][0], j2 + dir[u][1]));
							}
						}
					}
					
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}