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
//공백 포함해서 문자열 받기: getline(cin, s);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	int N, M;
	int i, j;

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> coins(N + 1);
		for (i = 1; i <= N; i++) {
			cin >> coins[i];
		}

		cin >> M;
		vector<int> dp(M + 1);
		dp[0] = 1;
		for (i = 1; i <= N; i++) {
			for (j = 0; j + coins[i] <= M; j++) {
				if (dp[j]) {
					dp[j + coins[i]] += dp[j];
				}
			}
		}

		cout << dp[M] << '\n';
	}

	return 0;
}