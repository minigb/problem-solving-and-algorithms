#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int temp;
	int ans, cnt;
	vector<int> money = { 500, 100, 50, 10, 5, 1 };
	int i, j, k;

	cin >> N;
	N = 1000 - N;
	ans = 0;
	for (i = 0; i < money.size(); i++) {
		ans += N / money[i];
		N %= money[i];
	}

	cout << ans << '\n';

	return 0;
}