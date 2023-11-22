#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int cnt, lazy; //cnt에는 켜진 스위치의 개수가 저장됨
};

vector<Node> tree;
int N;

void init();
int getCnt(int, int, int, int, int);
void update(int, int, int, int, int);
void propagate(int, int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M;
	int O, S, T;
	int i;

	cin >> N >> M;
	init();
	for (i = 0; i < M; i++) {
		cin >> O >> S >> T;
		if (O == 0) {
			update(1, 1, N, S, T);			
		}
		else {
			cout << getCnt(1, 1, N, S, T) << '\n';
		}
	}

	return 0;
}

void init()
{
	int base;

	for (base = 1; base < N; base *= 2);
	tree.resize(base * 2);

	return;
}

//index, start, end는 노드에 대한 정보
//인덱스가 index인 노드는 start~end번 노드의 정보를 갖고있다는 의미
int getCnt(int index, int start, int end, int from, int to)
{
	if (to < start || end < from) {
		return 0;
	}

	if (tree[index].lazy != 0) {
		propagate(index, start, end);
	}

	if (from <= start && end <= to) {
		return tree[index].cnt;
	}
	else {
		return getCnt(index * 2, start, (start + end) / 2, from, to) + getCnt(index * 2 + 1, (start + end) / 2 + 1, end, from, to);
	}
}

void update(int index, int start, int end, int from, int to)
{
	if (tree[index].lazy != 0) {
		propagate(index, start, end);
	}

	if (to < start || end < from) {
		return;
	}

	if (from <= start && end <= to) {
		tree[index].cnt = (end - start + 1) - tree[index].cnt;
		if (start != end) {
			tree[index * 2].lazy++;
			tree[index * 2 + 1].lazy++;
		}
	}
	else {
		update(index * 2, start, (start + end) / 2, from, to);
		update(index * 2 + 1, (start + end) / 2 + 1, end, from, to);
		tree[index].cnt = tree[index * 2].cnt + tree[index * 2 + 1].cnt;
	}

	return;
}

void propagate(int index, int start, int end)
{
	if (tree[index].lazy % 2) {
		tree[index].cnt = (end - start + 1) - tree[index].cnt;
	}

	if (start != end) {
		tree[index * 2].lazy += tree[index].lazy;
		tree[index * 2 + 1].lazy += tree[index].lazy;
	}

	tree[index].lazy = 0;

	return;
}