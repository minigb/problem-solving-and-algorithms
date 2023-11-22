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
	bool ans;
	int i;

	while (1) {
		getline(cin, s);
		len = s.length();

		if (len == 1 && s[0] == '.') {
			break;
		}

		ans = true;
		stack<char> stck;
		for (i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[') {
				stck.push(s[i]);
			}
			else if (s[i] == ')') {
				if (stck.empty()) {
					ans = false;
					break;
				}

				if (stck.top() != '(') {
					ans = false;
					break;
				}
				else {
					stck.pop();
				}
			}
			else if (s[i] == ']') {
				if (stck.empty()) {
					ans = false;
					break;
				}

				if (stck.top() != '[') {
					ans = false;
					break;
				}
				else {
					stck.pop();
				}
			}
		}

		if (!stck.empty()) {
			ans = false;
		}

		if (ans) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}

	return 0;
}