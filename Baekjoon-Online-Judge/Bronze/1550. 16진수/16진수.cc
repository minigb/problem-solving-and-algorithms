#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	using namespace std;

	string n;
	int answer, k;
	int i;

	cin >> n;
	reverse(n.begin(), n.end());

	answer = 0;

	for (i = 0; n[i]; i++)
	{
		if ('0' <= n[i] && n[i] <= '9')
			answer += (n[i] - 48) * pow(16, i);
			
		else
			answer += (n[i] - 55) * pow(16, i);
	}

	cout << answer << endl;

	return 0;
}