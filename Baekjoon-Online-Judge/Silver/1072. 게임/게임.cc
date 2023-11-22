#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll X, Y;
	ll Z;
	ll left, right, mid;
	ll ans;

	cin >> X >> Y;

	Z = Y * 100 / X;
	if (Z >= 99) {
		cout << -1 << '\n';
		return 0;
	}
	
	left = 1;
	for (right = 1; (ll)((double)(Y + right) / (X + right) * 100) == Z; right *= 2);
	right++;
	ans = 1;
	while (left < right) {
		mid = (left + right) / 2;
		if ((ll)((double)(Y + mid) / (X + mid) * 100) > Z) {
			ans = mid;
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
