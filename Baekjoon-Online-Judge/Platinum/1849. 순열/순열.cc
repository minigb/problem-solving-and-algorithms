#include <iostream>
#include <vector>
using namespace std;

typedef long long type;

class Tree {
public:
	Tree() {
		base = 0;
		cout << "YOU HAVE TO INITIALIZE THE TREE!!" << '\n';
	}
	Tree(int size) {
		for (base = 1; base < size; base *= 2);
		tree.resize(base * 2, 0);
	}

	//문제에 맞춰서 수정!!!
	void update(int at, type val)
	{
		for (at = at - 1 + base; at > 0; at /= 2) {
			tree[at] += val;
		}

		return;
	}

	type get(int from, int to)
	{
		from = from - 1 + base;
		to = to - 1 + base;
		type ret = 0;

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

private:
	vector<type> tree;
	int base;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int left, right, mid;
	int index, gotCnt;
	int i;

	cin >> N;
	vector<int> arr(N + 1);
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] = N - i - arr[i];
	}

	Tree cnt(N);
	for (i = 1; i <= N; i++) {
		cnt.update(i, 1);
	}

	vector<int> ans(N + 1);
	for (i = 1; i <= N; i++) {
		left = 1;
		right = N + 1;
		while (1) {
			if (left == right) {
				index = left;
				break;
			}

			mid = (left + right) / 2;
			gotCnt = cnt.get(mid, N);
			if (ans[mid] == 0) {
				gotCnt--;
			}

			if (gotCnt == arr[i]) {
				if (ans[mid]) {
					right = mid;
				}
				else {
					index = mid;
					break;
				}
			}
			else if (gotCnt < arr[i]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		ans[index] = i;
		cnt.update(index, -1);
	}

	for (i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}