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

int ans[10];

void Count(int n, int digit) {
	while (n) {
		ans[n % 10] += digit;
		n /= 10;
	}
}

void Solve(int a, int b, int digit) {
	while (a % 10 != 0 && a <= b) {
		Count(a, digit);
		a++;
	}
	while (b % 10 != 9 && a <= b) {
		Count(b, digit);
		b--;
	}
	
	if (a > b) {
		return;
	}

	a /= 10; b /= 10;
	for (int i = 0; i < 10; i++) {
		ans[i] += (b - a + 1) * digit;
	}

	Solve(a, b, digit * 10);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	
	Solve(1, n, 1);

	for (int i = 0; i < 10; i++) cout << ans[i] << ' ';
	cout << ENDL;

	return 0;
}