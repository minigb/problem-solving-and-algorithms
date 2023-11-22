#include <iostream>
#include <algorithm>

int a[1000][3];
int sum[1000][3];
int main()
{
	using namespace std;

	int n;
	int answer;
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];

	for (j = 0; j < 3; j++)
		sum[0][j] = a[0][j];
	for(i=1; i<n; i++)
		for (j = 0; j < 3; j++)
		{
			sum[i][j] = min(sum[i - 1][(j + 1) % 3], sum[i - 1][(j + 2) % 3]);
			sum[i][j] += a[i][j];
		}

	answer = 99999999;
	for (j = 0; j < 3; j++)
		answer = min(answer, sum[n - 1][j]);

	cout << answer << '\n';

	return 0;
}