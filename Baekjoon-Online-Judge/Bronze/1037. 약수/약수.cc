//4m 14s
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int all;
	int n[50];
	int i;

	cin >> all;
	for (i = 0; i < all; i++)
		cin >> n[i];

	sort(n, n + all);

	cout << (long long)n[0] * n[all - 1] << endl;

	return 0;
}