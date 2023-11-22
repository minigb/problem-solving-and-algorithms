#include <iostream>
using namespace std;

char a[64][64];
void Check(int, int, int);
int main()
{
	int n;
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];

	Check(0, 0, n);
	cout << '\n';

	return 0;
}

void Check(int h, int y, int n) //h는 시작 행, y는 시작 열
{
	int i, j;
	char chk;
	bool flag;

	if (n == 1)
	{
		cout << a[h][y];
		return;
	}

	flag = 0;
	chk = a[h][y];
	for (i = h; i < h + n; i++)
		for (j = y; j < y + n; j++)
			if (a[i][j] != chk)
			{
				flag = 1;
				break;
			}
	

	if (flag)
	{
		cout << '(';

		Check(h, y, n / 2);
		Check(h, y + n / 2, n / 2);
		Check(h + n / 2, y, n / 2);
		Check(h + n / 2, y + n / 2, n / 2);

		cout << ')';
	}
	else
	{
		cout << chk;

		return;
	}
}