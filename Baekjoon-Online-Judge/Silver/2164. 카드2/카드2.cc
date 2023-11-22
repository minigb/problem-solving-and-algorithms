#include <iostream>
#include <queue>

int main()
{
	using namespace std;

	int n;
	queue<int> que;
	int temp;
	int i;

	cin >> n;

	if (n == 1)
		cout << 1 << '\n';
	else
	{
		for (i = 1; i <= n; i++)
			que.push(i);

		while (1)
		{
			que.pop();
			if (que.size() == 1)
				break;

			temp = que.front();
			que.pop();
			que.push(temp);
		}

		cout << que.front() << '\n';
	}

	return 0;
}