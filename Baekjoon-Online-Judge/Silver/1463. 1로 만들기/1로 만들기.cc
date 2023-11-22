#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	bool chk[1000001]{};
	int cur, cnt, next;

	cin >> N;

	queue<pair<int, int>> que;
	que.push({ N, 0 });

	cnt = 0;
	while (!que.empty()) {
		cur = que.front().first;
		cnt = que.front().second;
		que.pop();

		if (cur < 1) {
			continue;
		}
		if (cur == 1) {
			break;
		}

		if (cur % 3 == 0) {
			next = cur / 3;
			if (!chk[next]) {
				chk[next] = 1;
				que.push({ next, cnt + 1 });
			}
		}
		if (cur % 2 == 0) {
			next = cur / 2;
			if (!chk[next]) {
				chk[next] = 1;
				que.push({ next, cnt + 1 });
			}
		}
		next = cur - 1;
		if (!chk[next]) {
			chk[next] = 1;
			que.push({ next, cnt + 1 });
		}
	}

	cout << cnt << '\n';

	return 0;
}