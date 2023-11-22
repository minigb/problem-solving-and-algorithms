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

ll getNum(vector<int>&, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7 , 8, 9 };
	int K;
	ll min_, max_;
	string min_str, max_str;
	int i;

	cin >> K;
	vector<char> math(K + 5);
	for (i = 0; i < K; i++) {
		cin >> math[i];
	}

	min_ = ll_inf;
	max_ = 0;
	do {
		for (i = 0; i < K; i++) {
			if (math[i] == '<') {
				if (!(arr[i] < arr[i + 1])) {
					break;
				}
			}
			else {
				if (!(arr[i] > arr[i + 1])) {
					break;
				}
			}
		}
		if (i == K) {
			ll num = getNum(arr, K + 1);
			string str = "";
			for (i = 0; i < K + 1; i++) {
				str += arr[i] + '0';
			}

			if (min_ > num) {
				min_ = num;
				min_str = str;
			}
			if (max_ < num) {
				max_ = num;
				max_str = str;
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));

	cout << max_str << '\n' << min_str << '\n';

	return 0;
}

ll getNum(vector<int>& arr, int K)
{
	ll ret = 0;
	int i;

	for (i = 0; i < K; i++) {
		ret *= 10;
		ret += arr[i];
	}

	return ret;
}