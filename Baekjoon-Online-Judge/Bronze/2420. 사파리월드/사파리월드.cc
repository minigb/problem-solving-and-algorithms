#include <iostream>

int main()
{
	using namespace std;

	long long n, m;

	cin >> n >> m;

	if (m - n > 0)
		cout << m-n << endl;
	else
		cout << n - m << endl;

	return 0;
}