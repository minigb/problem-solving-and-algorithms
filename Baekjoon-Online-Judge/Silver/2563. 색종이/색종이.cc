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
	int a, b;
	vector<vector<bool>> arr(105, vector<bool>(105, false));
	int ans = 0;
	int i, j;

	cin >> N;
	while (N--) {
		cin >> a >> b;
		for (i = a; i < a + 10; i++) {
			for (j = b; j < b + 10; j++) {
				arr[i][j] = true;
			}
		}
	}

	for (i = 0; i < 105; i++) {
		for (j = 0; j < 105; j++) {
			if (arr[i][j]) {
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}