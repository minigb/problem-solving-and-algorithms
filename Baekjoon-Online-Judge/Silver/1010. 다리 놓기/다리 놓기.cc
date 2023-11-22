//21m 27s
#include <iostream>

int main()
{
	using namespace std;

	int all;
	int n, m;
	long long answer;
	int i, j, k;
	long long test[2];
	
	cin >> all;

	for (k = 0; k < all; k++)
	{
		cin >> n >> m;
		
		answer = 1;
		if (m - n < n)
			n = m - n;

		for (i = m, j = 1; i > n, j <= m - n; i--, j++)
		{
			answer *= i;
			answer /= j;
		}

		for (; i > n; i--)
			answer *= i;
		for (; j <= m - n; j++)
			answer /= j;

		cout << answer << endl;
	}
	return 0;
}