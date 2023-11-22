#include <iostream>

int main()
{
	using namespace std;
	
	int l, a, b, c, d;
	int a1, b1;

	cin >> l >> a >> b >> c >> d;

	a1 = (a + c - 1) / c;
	b1 = (b + d - 1) / d;

	if (a1 > b1)
		l -= a1;
	else
		l -= b1;

	if (l < 0)
		l = 0;

	cout << l << endl;

	return 0;
}