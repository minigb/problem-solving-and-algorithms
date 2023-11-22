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

int main()
{
	string s1, s2, s3;
	int i, j, k;

	cin >> s1 >> s2 >> s3;
	vector<vector<vector<int>>> lcs(s1.length() + 1, vector<vector<int>> (s2.length() + 1, vector<int>(s3.length() + 1)));
	for (i = 0; s1[i]; i++) {
		for (j = 0; s2[j]; j++) {
			for (k = 0; s3[k]; k++) {
				if (s1[i] == s2[j] && s2[j] == s3[k]) {
					lcs[i + 1][j + 1][k + 1] = lcs[i][j][k] + 1;
				}
				else {
					lcs[i + 1][j + 1][k + 1] = max(max(lcs[i + 1][j + 1][k], lcs[i + 1][j][k + 1]), lcs[i][j + 1][k + 1]);
				}
			}			
		}
	}

	cout << lcs[s1.length()][s2.length()][s3.length()] << '\n';

	return 0;
}