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
	int x1, y1, x2, y2, x3, y3;

	cin >> x1 >> y1
		>> x2 >> y2
		>> x3 >> y3;

	if (x1 == x2) {
		cout << x3;
	}
	else if (x1 == x3) {
		cout << x2;
	}
	else {
		cout << x1;
	}

	cout << ' ';

	if (y1 == y2) {
		cout << y3;
	}
	else if (y1 == y3) {
		cout << y2;
	}
	else {
		cout << y1;
	}

	return 0;
}