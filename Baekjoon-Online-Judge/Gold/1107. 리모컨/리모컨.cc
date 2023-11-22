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

vector<bool> flag(10, true);

bool canPress(int);
int getDigit(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int temp;
	int ans;
	int i;
	
	cin >> N >> M;
	while (M--) {
		cin >> temp;
		flag[temp] = false;
	}
	
	ans = abs(N - 100); //100번부터 +-만 누르기
	for (i = 0; i <= 2000000; i++) {
		if (canPress(i)) {
			ans = min(ans, getDigit(i) + abs(N - i));
		}
	}
	
	cout << ans << '\n';

	return 0;
}

bool canPress(int N)
{
	if (N == 0) {
		return flag[0];
	}

	while (N) {
		if (!flag[N % 10]) {
			return false;
		}
		N /= 10;
	}

	return true;
}

int getDigit(int N)
{
	if (N == 0) {
		return 1;
	}

	int ret;

	for (ret = 0; N; N /= 10, ret++);

	return ret;
}