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
	int ans = int_inf;
	int left, right, sum;
	int i, j;

	cin >> N;
	vector<int> arr(N + 5);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.begin() + N);

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			left = i + 1;
			right = N - 1;
			sum = 0;
			while (left < right) {
				if (left == j) {
					left++;
				}
				if (right == j) {
					right--;
				}
				if (!(left < right)) {
					break;
				}

				sum = arr[left] + arr[right];
				ans = min(ans, abs(arr[i] + arr[j] - sum));
				if (sum > arr[i] + arr[j]) {
					right--;
				}
				else {
					left++;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}