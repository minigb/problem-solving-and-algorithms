#include <iostream>
#include <queue>

int main()
{
	using namespace std;

	int n, k;
	queue<int> que;
	int temp;
	int i;

	cin >> n >> k;
	
	for (i = 1; i <= n; i++)
		que.push(i);

	cout << '<';
	while (!que.empty())
	{
		for (i = 0; i < k - 1; i++)
		{
			temp = que.front();
			que.pop();
			que.push(temp);
		}
		cout << que.front();
		que.pop();
		n--;
		if (n)
			cout << ", ";
	}
	cout << '>';
	cout << '\n';

	return 0;
}