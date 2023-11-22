#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int a, b, c;

	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << 10000 + a * 1000 << endl;
	else if (a == b || b == c)
		cout << 1000 + b * 100 << endl;
	else if (a == c)
		cout << 1000 + a * 100 << endl;
	else
	{
		int max = a;
		if (max < b)
			max = b;
		if (max < c)
			max = c;

		cout << max * 100 << endl;
	}

	return 0;
}