#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음

int N, M;
vector<vector<int>> dp;
vector<vector<char>> map;
int get(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j;

	cin >> N >> M;

	map.resize(N, vector<char>(M));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			map[i][j] -= '0';
		}
	}

	dp.resize(N, vector<int>(M, -1));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			get(i, j);
		}
	}

	int ans = 0;
	for (i = 0; i < N; i++) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	cout << ans * ans << '\n';

	return 0;
}

int get(int y, int x)
{
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	if (map[y][x] == 0) {
		dp[y][x] = 0;
	}
	else if (y == N - 1 || x == M - 1) {
		dp[y][x] = 1;
	}
	else {
		dp[y][x] = min(min(get(y + 1, x), get(y, x + 1)), get(y + 1, x + 1)) + 1;
	}	
	
	return dp[y][x];
}