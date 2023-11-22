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
	string s;
	int ans = 0;
	int i;

	cin >> N;
	cin >> s;

	vector<int> arr;
	arr.push_back(-1);
	
	for (i = 0; i < N;) {
		if (s[i] == 'S') {
			arr.push_back(1);
			arr.push_back(-1);
			i += 1;
		}
		else {
			arr.push_back(1);
			arr.push_back(1);
			arr.push_back(-1);
			i += 2;
		}
	}

	ans = 0;
	for (i = 0; i < arr.size(); i++) {
		if (arr[i] == 1) {
			if (arr[i - 1] == -1) {
				arr[i - 1] = 0;
				ans++;
			}
			else if (arr[i + 1] == -1) {
				arr[i + 1] = 0;
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}