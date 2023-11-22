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

int gcd(int k, int l) { return l ? gcd(l, k % l) : k; }
int lcm(int k, int l) { return k / gcd(k, l) * l; }
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b;

	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;

	return 0;
}