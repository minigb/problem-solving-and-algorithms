#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int l, a[50], n;
	int left, right;
	int i;

	cin >> l;
	for (i = 0; i < l; i++)
		cin >> a[i];
	cin >> n;
	
	sort(a, a + l);
	
	for(i=0; i<l; i++)
		if (a[i] == n)
		{
			cout << 0 << endl;
			return 0;
		}

	if (n < a[0])
		cout << n * (a[0] - n) - 1 << endl;

	else
	{
		for (i = 0; i < l - 1; i++)
		{
			if (a[i] < n && n < a[i + 1])
				break;
		}

		cout << (n - a[i]) * (a[i + 1] - n) - 1 << endl;
	}
	
	return 0;
}