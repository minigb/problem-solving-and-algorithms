#include <iostream>
#include <queue>
#include <string>
using namespace std;

int D(int);
int S(int);
int L(int);
int R(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	int a, b;
	bool chk[10000];
	queue<pair<int, string>> que;
	string s;
	int temp, cur;
	int i, k;

	cin >> t;

	for (k = 0; k < t; k++) {
		cin >> a >> b;
		for (i = 0; i < 10000; i++) {
			chk[i] = 0;
		}

		while (!que.empty()) {
			que.pop();
		}

		que.push(make_pair(a, ""));
		chk[a] = 1;

		while (!que.empty()) {
			cur = que.front().first;
			s = que.front().second;
			que.pop();

			//찾으면 종료
			if (cur == b) {
				cout << s << '\n';
				break;
			}
			
			//DSLR 적용
			temp = D(cur);
			if (!chk[temp]) {
				chk[temp] = 1;
				que.push(make_pair(temp, s + 'D'));
			}

			temp = S(cur);
			if (!chk[temp]) {
				chk[temp] = 1;
				que.push(make_pair(temp, s + 'S'));
			}

			temp = L(cur);
			if (!chk[temp]) {
				chk[temp] = 1;
				que.push(make_pair(temp, s + 'L'));
			}

			temp = R(cur);
			if (!chk[temp]) {
				chk[temp] = 1;
				que.push(make_pair(temp, s + 'R'));
			}
		}
	}

	return 0;
}

int D(int n)
{
	return (n * 2) % 10000;
}

int S(int n)
{
	if (n == 0) {
		n = 10000;
	}
	n--;

	return n;
}

int L(int n)
{
	int temp = n / 1000;
	n %= 1000;
	n *= 10;
	n += temp;

	return n;
}

int R(int n)
{
	int temp = n % 10;
	n /= 10;
	n += temp * 1000;

	return n;
}