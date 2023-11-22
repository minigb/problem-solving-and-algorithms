#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	vector<vector<int>> fri;
	vector<vector<int>> adj;
	vector<int> cnt;
	char c;
	int i, j;

	cin >> N;
	fri.resize(N + 1, vector<int>(N + 1));
	adj.resize(N + 1);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> c;
			if (c == 'Y') {
				fri[i][j] = 1;
				adj[i].push_back(j);
			}
			else {
				fri[i][j] = 0;
			}
		}
	}

	cnt.resize(N + 1, 0);
	for (i = 1; i <= N; i++) {
		for (int next : adj[i]) {
			for (int next_next : adj[next]) {
				fri[i][next_next] = 1;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			cnt[i] += fri[i][j];
		}
	}

	cout << *max_element(cnt.begin(), cnt.end()) << '\n';


	return 0;
}