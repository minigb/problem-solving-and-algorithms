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
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ENDL '\n'
#define PI acos(-1)

const int NMAX = 202020;
int chk(int n)
{
	return (n == 2 || n == 0 || n == 1 || n == 8);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> cnt(10);

	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}

	bool related = true;
	for (int i = 0; i < 10; i++) {
		if (chk(i) == false && cnt[i] > 0) {
			related = false;
			break;
		}
	}

	int ans = -1;
	if (related) {
		if (cnt[2] && cnt[0] && cnt[1] && cnt[8]) { //밀접한 수
			if (cnt[2] == cnt[0] && cnt[0] == cnt[1] && cnt[1] == cnt[8]) {
				ans = 8;
			}
			else {
				ans = 2;
			}
		}
		else {
			ans = 1;
		}
	}
	else {
		ans = 0;
	}

	cout << ans << ENDL;

	return 0;
}