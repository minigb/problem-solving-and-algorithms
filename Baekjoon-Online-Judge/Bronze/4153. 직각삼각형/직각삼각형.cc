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
	ll arr[3];
	int i;

	while (1) {
		for (i = 0; i < 3; i++) {
			cin >> arr[i];
		}

		if (!(arr[0] || arr[1] || arr[2])) {
			break;
		}

		sort(arr, arr + 3);

		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}

	return 0;
}