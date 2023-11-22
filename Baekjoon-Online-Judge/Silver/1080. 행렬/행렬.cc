#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음
//공백 포함해서 문자열 받기: getline(cin, s);

void flip(vector<vector<char>>&, int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int cnt = 0;
	bool same = true;
	int i, j;

	cin >> N >> M;
	vector<vector<char>> arr1(N, vector<char>(M)), arr2(N, vector<char>(M));
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> arr2[i][j];
		}
	}

	for (i = 0; i + 2 < N; i++) {
		for (j = 0; j + 2 < M; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				flip(arr1, i, j);
				cnt++;
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (arr1[i][j] != arr2[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) {
			break;
		}
	}

	if (!same) {
		cout << -1 << '\n';
	}
	else {
		cout << cnt << '\n';
	}

	return 0;
}

void flip(vector<vector<char>>& arr, int y, int x)
{
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			char& c = arr[y + i][x + j];
			if (c == '0') {
				c = '1';
			}
			else {
				c = '0';
			}
		}
	}
}