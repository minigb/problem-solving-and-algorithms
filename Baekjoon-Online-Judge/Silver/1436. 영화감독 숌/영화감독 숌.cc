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
	vector<ll> arr;
	ll digit, n;
	int size;
	int i;

	cin >> N;
	arr.push_back(666);

	digit = 1000;
	while (arr.size() < N) {
		size = arr.size();
		for (n = 0; n <= 9; n++) {
			for (i = 0; i < size; i++) {
				arr.push_back(arr[i] + digit * n);
				arr.push_back(arr[i] * 10 + n);
			}
		}
		
		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		digit *= 10;
	}

	cout << arr[N - 1] << '\n';

	return 0;
}