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
	string s;
	int len;
	int cnt[2]{};
	int i;

	cin >> s;
	len = s.length();

	cnt[s[0] - '0']++;
	for (i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) {
			cnt[s[i] - '0']++;
		}
	}

	cout << min(cnt[0], cnt[1]) << '\n';

	return 0;
}