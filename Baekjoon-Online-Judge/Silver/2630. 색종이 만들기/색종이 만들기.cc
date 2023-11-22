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

vector<vector<int>> arr;
int cnt[2];

void get(int y, int x, int size);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i, j;

	cin >> N;
	arr.resize(N + 5, vector<int>(N + 5));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	get(1, 1, N);

	cout << cnt[0] << '\n'
		<< cnt[1] << '\n';

	return 0;
}

void get(int y, int x, int size)
{
	if (size == 1) {
		cnt[arr[y][x]]++;
		return;
	}
	
	bool flag = true;
	int i, j;

	for (i = y; i < y + size; i++) {
		for (j = x; j < x + size; j++) {
			if (arr[i][j] != arr[y][x]) {
				flag = false;
				break;
			}
		}
	}

	if (flag) {
		cnt[arr[y][x]]++;
	}
	else {
		get(y, x, size / 2);
		get(y + size / 2, x, size / 2);
		get(y, x + size / 2, size / 2);
		get(y + size / 2, x + size / 2, size / 2);
	}
}