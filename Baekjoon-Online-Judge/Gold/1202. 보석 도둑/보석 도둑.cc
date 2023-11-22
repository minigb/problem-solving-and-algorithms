/*
와....
또 하나 배워갑니다...
이거 두 번 틀리고 나서 풀이를 봤는데
이게 막 비율을 따져서 담는 그리디인줄 알았다
근데 그게 아니었고...

그냥 ㄹㅇ 그리디하게 비싼거부터 담으면 되는데
이 가방을 지금 사용했는지를 확인해야 되니까...
그게 문제였고, 거기서 시간 초과가 난거였는데

multiset이라는 컨테이너를 사용해서
사용한 가방은 바로바로 지워주면 됐다.. 와 진짜 대박

그래서 set, map 등등
컨테이너 공부를 하게 되었는데

신기하구만

내일 나오면 좋겠다
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
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음
//공백 포함해서 문자열 받기: getline(cin, s);

bool sortby(pair<int, int>, pair<int, int>);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	ll ans;
	int temp;
	int i;

	cin >> N >> K;
	vector<pair<int, int>> jewel(N); //무게, 가격
	for (i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	multiset<int> bag;
	for (i = 0; i < K; i++) {
		cin >> temp;
		bag.insert(temp);
	}
	sort(jewel.begin(), jewel.end(), sortby);

	ans = 0;
	for (i = 0; i < N; i++) {
		auto iter = bag.lower_bound(jewel[i].first);
		if (iter != bag.end()) {
			ans += (ll)jewel[i].second;
			bag.erase(iter);
		}
	}

	cout << ans << '\n';

	return 0;
}

bool sortby(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}