#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);
ll GCD(ll k, ll l) { return l ? GCD(l, k % l) : k; }

struct Point {
	int x, y;
};

bool sortby(Point a, Point b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x > b.x;
}

class SegmentTree {
public:
	SegmentTree() {}
	SegmentTree(int n) {
		for (base = 1; base < n; base *= 2);
		tree.resize(base * 2, 0);
	}
	void Update(int index, int value) {
		for (index += base; index >= 1; index /= 2) {
			tree[index] += value;
		}
	}
	int Get(int from, int to) {
		from += base;
		to += base;
		int return_value = 0;
		while (from <= to) {
			if (from % 2 == 1) {
				return_value += tree[from++];
			}
			if (to % 2 == 0) {
				return_value += tree[to--];
			}
			from /= 2;
			to /= 2;
		}
		return return_value;
	}

private:
	int base;
	vector<int> tree;
};

long long Solution(vector<Point>& point_vector) {
	sort(point_vector.begin(), point_vector.end(), sortby);

	map<int, int> cordinate_number;
	for (const auto& point : point_vector) {
		cordinate_number[point.x] = 0;
		cordinate_number[point.y] = 0;
	}
	int number_index = -1;
	for (auto iter = cordinate_number.begin(); iter != cordinate_number.end(); ++iter) {
		iter->second = ++number_index;
	}

	SegmentTree counting_tree(cordinate_number.size());
	long long answer = 0;
	for (const auto& point : point_vector) {
		const int& cur_index = cordinate_number[point.y];
		answer += counting_tree.Get(0, cur_index);
		counting_tree.Update(cur_index, 1);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<Point> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].x >> arr[i].y;
		}
		cout << Solution(arr) << kEndl;
	}	
}