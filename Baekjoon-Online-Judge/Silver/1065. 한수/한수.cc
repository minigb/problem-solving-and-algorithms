#include <iostream>

int main()
{
	using namespace std;

	int n;
	int cnt;
	int a[3], temp;
	int i, j;
	
	cin >> n;

	if (n == 1000)
		n--;

	if (n <= 99)
		cnt = n;
	else
	{
		cnt = 99;
		for (j = 100; j <= n; j++)
		{
			temp = j;
			for (i = 2; i >= 0; i--)
			{
				a[i] = temp % 10;
				temp /= 10;
			}
			
			if (a[0] - a[1] == a[1] - a[2])
				cnt++;
		}
	}

	cout << cnt << '\n';

	
	
	

	return 0;
}