#include <iostream>

int main()
{
	using namespace std;

	long long a, b, c;

	cin >> a >> b >> c;

	if (b < c)
		cout << (int)((double)a / b * c) << endl;
	else
		cout << (int)((double)a * b / c) << endl;

	return 0;
}