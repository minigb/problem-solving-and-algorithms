#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> tree;
int base;
int N;
vector<ll> arr;

void init();
void update(int, ll);
ll getAns(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q;
	int a, b, c;
	ll d;
	int i;

	cin >> N >> Q;
	arr.resize(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init();

	for (i = 0; i < Q; i++) {
		cin >> a >> b >> c >> d;
		cout << getAns(a, b) << '\n';
		update(c, d);
	}

	return 0;
}

void init()
{
	int i;

	for (base = 1; base < N; base *= 2);
	tree.resize(base * 2);
	for (i = 0; i < N; i++) {
		tree[i + base] = arr[i];
	}

	for (i = base - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	return;
}

void update(int at, ll value)
{
	at = at - 1 + base;
	tree[at] = value;

	for (at /= 2; at > 0; at /= 2) {
		tree[at] = tree[at * 2] + tree[at * 2 + 1];
	}

	return;
}

ll getAns(int from, int to)
{
	ll ret = 0;
	from = from - 1 + base;
	to = to - 1 + base;
	if (from > to) {
		swap(from, to);
	}

	while (from <= to) {
		if (from % 2 == 1) {
			ret += tree[from++];
		}
		if (to % 2 == 0) {
			ret += tree[to--];
		}
		from /= 2;
		to /= 2;
	}

	return ret;
}