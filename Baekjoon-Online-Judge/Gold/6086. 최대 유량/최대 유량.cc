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
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502

#define MAX 60
int alpha_to_int(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a' + 26;
	}
	return c - 'A';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int source = 0, sink = 25;
	int total_flow = 0;

	vector<vector<int>> capa(MAX, vector<int>(MAX, 0)), flow(MAX, vector<int>(MAX, 0));
	vector<vector<int>> adj(MAX);

	cin >> N;
	while (N--) {
		char f, t;
		int from, to, c;

		cin >> f >> t >> c;
		from = alpha_to_int(f);
		to = alpha_to_int(t);

		capa[from][to] += c;
		capa[to][from] += c;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	total_flow = 0;
	while (1) {
		vector<int> prev(MAX, -1);
		queue<int> que;
		que.push(source);
		prev[source] = source;

		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			for (int next : adj[cur]) {
				if (prev[next] != -1) {
					continue;
				}

				if (capa[cur][next] - flow[cur][next] > 0) {
					prev[next] = cur;
					que.push(next);
				}
			}
		}

		if (prev[sink] == -1) {
			break;
		}

		int min_flow = int_inf;
		for (int cur = sink; cur != source; cur = prev[cur]) {
			int before = prev[cur];
			min_flow = min(min_flow, capa[before][cur] - flow[before][cur]);
		}
		for (int cur = sink; cur != source; cur = prev[cur]) {
			int before = prev[cur];
			flow[before][cur] += min_flow;
			flow[cur][before] -= min_flow;
		}
		total_flow += min_flow;
	}

	cout << total_flow << '\n';

	return 0;
}