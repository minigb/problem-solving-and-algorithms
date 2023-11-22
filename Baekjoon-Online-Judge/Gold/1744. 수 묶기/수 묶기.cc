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
	int N;
	vector<ll> plus, minus;
	ll ans = 0;
	ll input;
	int i;

	cin >> N;
	while (N--) {
		cin >> input;
		if (input > 0) {
			plus.push_back(input);
		}
		else {
			minus.push_back(input);
		}
	}

	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());
	
	for (i = 0; i + 1 < plus.size(); i += 2) {
		ans += max(plus[i] * plus[i + 1], plus[i] + plus[i + 1]);
	}
	if (i < plus.size()) {
		ans += plus[i];
	}

	for (i = 0; i + 1 < minus.size(); i += 2) {
		ans += minus[i] * minus[i + 1];
	}
	if (i < minus.size()) {
		ans += minus[i];
	}

	cout << ans << '\n';

	return 0;
}