#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int base;
vector<int> tree;
vector<pair<int, int>> indexs;
int N;

int getIndex(int);
int getCnt(int);
void update(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> arr;
	int temp;
	int index;
	long long ans;
	int i;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	for (i = 0; i < N; i++) {
		cin >> temp;
		indexs.push_back({ temp, i });
	}
	sort(indexs.begin(), indexs.end());

	for (base = 1; base < N; base*=2);
	tree.resize(base * 2, 0);

	ans = 0;
	for (i = 0; i < N; i++) {
		index = getIndex(arr[i]);
		ans += (long long)getCnt(index);
		update(index);
	}

	cout << ans << '\n';

	return 0;
}

int getIndex(int n)
{
	int left = 0, right = N, mid;

	while (1) {
		if (left == right) {
			return indexs[left].second;
		}

		mid = (left + right) / 2;
		if (indexs[mid].first == n) {
			return indexs[mid].second;
		}
		else if (indexs[mid].first < n) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
}

int getCnt(int from)
{
	from = from - 1 + base;
	int to = N - 2 + base;
	int cnt = 0;

	while (from <= to) {
		if (from % 2 == 1) {
			cnt += tree[from++];
		}
		if (to % 2 == 0) {
			cnt += tree[to--];
		}
		from /= 2;
		to /= 2;
	}

	return cnt;
}

void update(int index)
{
	index = index - 1 + base;
	for (; index > 0; index /= 2) {
		tree[index]++;
	}

	return;
}