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

string s;
bool palin(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	while (1) {
		cin >> s;
		if (s.length() == 1 && s[0] == '0') {
			break;
		}

		if (palin(0, s.length() - 1)) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}

bool palin(int start, int end)
{
	if (start >= end) {
		return true;
	}
	
	if (s[start] == s[end]) {
		return palin(start + 1, end - 1);
	}
	else {
		return false;
	}
}