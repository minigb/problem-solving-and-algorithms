//58m 58m
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;
	
	int a[50][50];
	int n, m;
	int count1[43][43], count2[43][43];
	char c;
	int answer;
	int i, j, i2, j2;

	cin >> n >> m;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'B')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}

	for (i = 0; i <= n - 8; i++)
		for (j = 0; j <= m - 8; j++)
		{
			count1[i][j] = 0;
			count2[i][j] = 0;
			for (i2 = i; i2 < i + 8; i2++)
				for (j2 = j; j2 < j + 8; j2++)
				{
					count1[i][j] += (((i2 - i + j2 - j + a[i][j]) % 2) != a[i2][j2]);
					count2[i][j] += (((i2 - i + j2 - j + a[i][j] + 1) % 2) != a[i2][j2]);
				}
		}
	
	answer = 64;
	for (i = 0; i <= n - 8; i++)
	{
		for (j = 0; j <= m - 8; j++)
		{
			answer = min(answer, count1[i][j]);
			answer = min(answer, count2[i][j]);
		}

	}

	cout << answer << endl;
	return 0;
}