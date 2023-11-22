#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge {
	int node1, node2;
	double weight;
};

vector<vector<int>> node;
vector<Edge> edges;
vector<int> root;

int find(int);
void unite(int, int);
long double len(int, int);
bool sortby(Edge, Edge);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	Edge e;
	int a, b;
	long double sum;
	int i, j;

	cin >> n >> m;
	node.resize(n + 1, vector<int>(2));
	for (i = 1; i <= n; i++) {
		cin >> node[i][0] >> node[i][1];
	}
	root.resize(n + 1, -1);

	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			e.node1 = i;
			e.node2 = j;
			e.weight = len(i, j);
			edges.push_back(e);
		}
	}

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		unite(a, b);
	}

	sum = 0;
	sort(edges.begin(), edges.end(), sortby);
	for (i = 0; i < edges.size(); i++) {
		if (find(edges[i].node1) != find(edges[i].node2)) {
			unite(edges[i].node1, edges[i].node2);
			sum += edges[i].weight;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << sum << '\n';

	return 0;
}

long double len(int node1, int node2)
{
	long long a, b;

	a = abs(node[node1][0] - node[node2][0]);
	b = abs(node[node1][1] - node[node2][1]);

	return sqrt(a * a + b * b);
}

int find(int a)
{
	if (root[a] == -1) {
		return a;
	}
	return root[a] = find(root[a]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (x != y) {
		root[x] = y;
	}

	return;
}

bool sortby(Edge a, Edge b)
{
	return a.weight < b.weight;
}