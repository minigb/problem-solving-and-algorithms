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
	double x1, y1, r1;
	double x2, y2, r2;
	double dist;

	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << '\n';
			continue;
		}

		dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		
		if (dist > r1 + r2) {
			cout << 0 << '\n';
		}
		else if (dist == r1 + r2 || dist == abs(r1 - r2)) {
			cout << 1 << '\n';
		}
		else if (dist < max(r1, r2) - min(r1, r2)) {
			cout << 0 << '\n';
		}
		else {
			cout << 2 << '\n';
		}
	}

	return 0;
}