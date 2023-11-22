/*
아 씨발
문제 잘못 읽어서 풀이 틀린줄 알고 한참 헤맸네

입력으로 주어지는 게
점수가 아니라 등수야

씨발.....
*/

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
	int T;
	int N;
	int ans, min_;
	int i;

	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>> arr(N);
		for (i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr.begin(), arr.end());

		ans = 1;
		min_ = arr[0].second;
		for (i = 1; i < N; i++) {
			if (arr[i].second < min_) {
				ans++;
				min_ = arr[i].second;
			}
		}

		cout << ans << '\n';
	}


	return 0;
}