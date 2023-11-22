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
	int T;
	string s;
	int ans;
	int cnt;
	int i;

	cin >> T;
	while (T--) {
		cin >> s;

		ans = 0;
		cnt = 0;
		for (i = 0; s[i]; i++) {
			if (s[i] == 'O') {
				ans += ++cnt;
			}
			else {
				cnt = 0;
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}