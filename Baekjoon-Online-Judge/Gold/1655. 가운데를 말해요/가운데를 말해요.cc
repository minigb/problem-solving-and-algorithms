#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct comp {
	bool operator () (int a, int b) {
		return a > b;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, comp> min_heap;
	int cur;
	int temp, temp2;
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) { //i가 짝수면 max에, 홀수면 min에 넣을 차례
		cin >> cur;

		if (i % 2 == 0) {
			max_heap.push(cur);
		}
		else {
			min_heap.push(cur);
		}

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			temp = max_heap.top();
			max_heap.pop();
			temp2 = min_heap.top();
			min_heap.pop();

			max_heap.push(temp2);
			min_heap.push(temp);
		}
		cout << max_heap.top() << '\n';
	}

	return 0;
}