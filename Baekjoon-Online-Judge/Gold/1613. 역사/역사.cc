#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K, S;
	vector<vector<int>> graph; //-1이면 i->j 순서, 1이면 j->i순서, 0이면 모름
	int a, b;
	int i, j, k;

	cin >> N >> K;
	graph.resize(N + 1, vector<int> (N + 1));
	for (i = 0; i < K; i++) {
		cin >> a >> b;
		graph[a][b] = -1;
		graph[b][a] = 1;
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (graph[i][k] == -1 && graph[k][j] == -1) {
					graph[i][j] = -1;
				}
				else if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
				}
			}
		}
	}

	cin >> S;
	while (S--) {
		cin >> a >> b;
		cout << graph[a][b] << '\n';
	}	

	return 0;
}