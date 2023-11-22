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
	int N, X;
	int ans = 0;
	int i;

	cin >> N;
	vector<int> arr(N + 5);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;
	
	sort(arr.begin(), arr.begin() + N);
	ans = 0;
	for (i = 0; i < N; i++) {
		if (binary_search(arr.begin() + i + 1, arr.begin() + N, X - arr[i])) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}