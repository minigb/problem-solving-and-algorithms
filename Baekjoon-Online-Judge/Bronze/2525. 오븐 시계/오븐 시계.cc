#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int a, b, c;

	cin >> a >> b;
	cin >> c;

	b += c;
	if (b >= 60)
	{
		a += b / 60;
		b %= 60;
	}
	if (a >= 24)
		a %= 24;

	cout << a << ' ' << b << endl;

	return 0;
}