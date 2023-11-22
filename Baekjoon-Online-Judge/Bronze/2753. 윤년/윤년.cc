#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int n;
	int flag;

	cin >> n;

	if (n % 400 == 0)
		flag = 1;
	else if (n % 100 == 0)
		flag = 0;
	else if (n % 4 == 0)
		flag = 1;
	else
		flag = 0;

	cout << flag << endl;

	return 0;
}