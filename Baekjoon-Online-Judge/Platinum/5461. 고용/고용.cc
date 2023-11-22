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
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
#define ENDL '\n'
#define PI acos(-1)

bool sortby(pair<pair<double, double>, int> a, pair<pair<double, double>, int> b) {
	if (a.first.first / a.first.second == b.first.first / b.first.second) {
		return a.first.second < b.first.second;
	}
	return a.first.first / a.first.second < b.first.first / b.first.second;
}

struct compby {
	bool operator () (pair<pair<double, double>, int> a, pair<pair<double, double>, int> b) {
		return a.first.second < b.first.second;
		//Q가 큰 것부터 뽑히게
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	double W;
	int i;

	cin >> N >> W;
	vector<pair<pair<double, double>, int>> arr(N + 5);
	for (i = 0; i < N; i++) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.begin() + N, sortby);

	priority_queue<pair<pair<double, double>, int>, vector<pair<pair<double, double>, int>>, compby> pq;
	double ans_cost = 1e10, ans_cnt = 0, ans_idx = -1;
	double K = 0;
	double sum = 0;

	vector<pair<double, int>> ans;
	for(i = 0; i < N; i++) {
		K = arr[i].first.first / arr[i].first.second;
		sum += arr[i].first.second;
		pq.push(arr[i]);

		while (sum * K > W && !pq.empty()) {
			sum -= pq.top().first.second;
			pq.pop();
		}

		if (pq.size() > ans_cnt || (pq.size() == ans_cnt && ans_cost > sum* K)) {
			ans_cnt = pq.size();
			ans_cost = sum * K;
			ans_idx = i;
		}
	}

	cout << ans_cnt << ENDL;
	for (i = 0; i <= ans_idx; i++) {
		ans.push_back({ arr[i].first.second, arr[i].second });
	}
	sort(ans.begin(), ans.end());
	for (i = 0; i < ans_cnt; i++) {
		cout << ans[i].second << ENDL;
	}

	return 0;
}