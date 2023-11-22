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
	int N;
	int input;
	int next;
	bool notOkay = false;
	int i;

	cin >> N;
	vector<char> ans;
	stack<int> stck;
	next = 1;
	for (i = 0; i < N; i++) {
		cin >> input;

		if (!stck.empty() && input == stck.top()) {
			stck.pop();
			ans.push_back('-');
			continue;
		}

		if (stck.empty()) {
			if (next > input) {
				notOkay = true;
				break;
			}
			else {
				stck.push(next++);
				ans.push_back('+');
			}
		}
		else if (input < stck.top()) {
			notOkay = true;
			break;
		}

		while (input > stck.top() && next <= N) {
			stck.push(next++);
			ans.push_back('+');
		}
		if (next > N && input > stck.top()) {
			notOkay = true;
			break;
		}
		stck.pop();
		ans.push_back('-');
	}

	if (notOkay) {
		cout << "NO" << '\n';
	}
	else {
		for (char c : ans) {
			cout << c << '\n';
		}
	}

	return 0;
}