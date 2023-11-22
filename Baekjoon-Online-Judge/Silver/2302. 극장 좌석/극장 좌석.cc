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
	int N, M;
	int temp;

	cin >> N >> M;
	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}

	vector<bool> vip(N + 1);
	while (M--) {
		cin >> temp;
		vip[temp] = true;
	}

	vector<int> dp(N + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] += dp[i - 1];
		if (!vip[i] && !vip[i - 1]) {
			dp[i] += dp[i - 2];
		}
	}

	cout << dp[N] << '\n';

	return 0;
}