#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	int N;
	float sum;
	float cnt;
	int i;

	cin >> T;
	while (T--) {
		cin >> N;
		vector<float> arr(N);
		sum = 0;
		for (i = 0; i < N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		cnt = 0;
		for (i = 0; i < N; i++) {
			if (arr[i] > sum / N) {
				cnt++;
			}
		}

		cout << fixed;
		cout.precision(3);
		cout << cnt / N * 100 << '%' << '\n';
	}

	return 0;
}