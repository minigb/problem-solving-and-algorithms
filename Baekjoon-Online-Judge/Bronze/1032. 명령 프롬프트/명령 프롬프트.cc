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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int len;
	bool flag;
	int i, j;

	cin >> N;
	vector<string> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	len = arr[0].length();
	for (j = 0; j < len; j++) {
		flag = true;
		for (i = 0; i < N; i++) {
			if (arr[i][j] != arr[0][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << arr[0][j];
		}
		else {
			cout << '?';
		}
	}

	return 0;
}