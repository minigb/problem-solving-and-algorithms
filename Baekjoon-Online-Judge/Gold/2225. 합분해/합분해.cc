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
#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	int i, j, k;

	cin >> N >> K;
	N = K + N - 1;
	K = K - 1;
	vector<vector<int>> combi(N + 1, vector<int>(N + 1));
	for (i = 1; i <= N; i++) {
		combi[i][0] = combi[i][i] = 1;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i - 1; j++) {
			combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
			combi[i][j] %= MOD;
		}
	}

	cout << combi[N][K] << '\n';

	return 0;
}