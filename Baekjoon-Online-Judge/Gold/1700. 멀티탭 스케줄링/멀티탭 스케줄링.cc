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
	int N, K;
	int ans;
	int howmany;
	int cur;
	int i, j;

	cin >> N >> K;
	vector<int> order(K), cnt(K + 1, 0);
	for (i = 0; i < K; i++) {
		cin >> order[i];
		cnt[order[i]]++;
	}

	ans = 0;
	howmany = 0;
	vector<bool> plug(K + 1, false);
	for (i = 0; i < K; i++) {
		cur = order[i];
		cnt[cur]--;

		if (plug[cur]) {
			continue;
		}

		if (howmany < N) {
			howmany++;
			plug[cur] = true;
			continue;
		}

		for (j = 1; j <= K; j++) {
			if (plug[j] && cnt[j] == 0) {
				ans++;
				plug[j] = false;
				plug[cur] = true;
				break;
			}
		}
		if (j <= K) {
			continue;
		}

		int max_ = 0, idx;
		for (j = 1; j <= K; j++) {
			if (plug[j]) {
				for (int k = i + 1; k < K; k++) {
					if (order[k] == j) {
						if (max_ < k) {
							max_ = k;
							idx = j;
						}
						break;
					}
				}
			}
		}

		ans++;
		plug[idx] = false;
		plug[cur] = true;
	}

	cout << ans << '\n';

	return 0;
}