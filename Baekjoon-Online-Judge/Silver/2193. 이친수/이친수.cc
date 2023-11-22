#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	long long dp[91][2]{};
	int i;

	cin >> N;

	dp[1][0] = 0;
	dp[1][1] = 1;
	for (i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1] << endl;

	return 0;
}