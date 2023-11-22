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

int getNext(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<bool> self(10001, true);
	int i, j;

	for (i = 1; i <= 10000; i++) {
		if (self[i]) {
			for (j = getNext(i); j <= 10000; j = getNext(j)) {
				self[j] = false;
			}
		}
	}

	for (i = 1; i <= 10000; i++) {
		if (self[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}

int getNext(int n) {
	int ret = n;

	for (; n; n /= 10) {
		ret += n % 10;
	}

	return ret;
}