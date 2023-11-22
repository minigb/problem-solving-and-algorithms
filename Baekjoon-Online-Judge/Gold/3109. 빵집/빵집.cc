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

int R, C;
int ans = 0;
vector<vector<bool>> chk;

bool get(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char c;
	int i, j, x, y;

	cin >> R >> C;
	chk.resize(R + 5, vector<bool>(C + 5, false));
	//0: 못 감(불가능 한 경우거나, 앞에서 이미 차지함), 1: 가 봐

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cin >> c;
			if (c == '.') {
				chk[i][j] = true;
			}
			else {
				chk[i][j] = false;
			}
		}
	}

	ans = 0;
	for (i = 1; i <= R; i++) {
		if (get(i, 1)) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}

bool get(int y, int x)
{
	if (x == C) {
		chk[y][x] = false;
		return true;
	}

	bool result;
	if (chk[y - 1][x + 1]) {
		chk[y - 1][x + 1] = false;
		if (get(y - 1, x + 1)) {
			return true;
		}
	}

	if (chk[y][x + 1]) {
		chk[y][x + 1] = false;
		if (get(y, x + 1)) {
			return true;
		}
	}

	if (chk[y + 1][x + 1]) {
		chk[y + 1][x + 1] = false;
		if (get(y + 1, x + 1)) {
			return true;
		}
	}
	
	return false;
}