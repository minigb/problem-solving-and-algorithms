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
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ENDL '\n'
#define PI acos(-1)
using vvint = vector<vector<int>>;
const int MOD = 10000;

vvint expo(vvint arr, int cnt);
vvint mul(vvint a, vvint b);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;

	while (cin >> N) {
		if (N == -1) break;
		vvint arr = { {1, 1}, {1, 0} };
		vvint ans = expo(arr, N);
		cout << ans[1][0] << ENDL;
	}

	return 0;
}

vvint expo(vvint arr, int cnt)
{
	vvint ret = { {1, 0}, {0, 1} };
	vvint x = arr;

	while (cnt) {
		if (cnt % 2) {
			ret = mul(ret, x);
		}
		cnt /= 2;
		x = mul(x, x);
	}

	return ret;
}

vvint mul(vvint a, vvint b) {
	vvint ret(2, vector<int>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= MOD;
			}
		}
	}

	return ret;
}