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
	vector<pair<int, int>> arr(10, { 0, 0 });
	int temp;
	int i, j;

	for (i = 0; i < 5; i++) {
		arr[i].second = i + 1;
		for (j = 0; j < 4; j++) {
			cin >> temp;
			arr[i].first += temp;
		}
	}

	sort(arr.begin(), arr.begin() + 5, greater<>());

	cout << arr[0].second << ' ' << arr[0].first << '\n';

	return 0;
}