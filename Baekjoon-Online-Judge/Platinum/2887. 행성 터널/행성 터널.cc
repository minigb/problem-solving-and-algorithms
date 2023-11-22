//으악
//30분 걸림

//처음에 틀렸던 이유는
//노드가 최대 10만개인데, nC2로 모든 edge를 구하면
//메모리 초과가 나옴...
//어떻게 보면 당연한 얘기

//이 문제에서 어차피 가능한 edge 중 길이가 짧은 것들을 먼저 뽑아서 사용하니까
//x, y, z좌표 각각을 기준으로 해서
//노드들을 오름차순 정렬해 놓고
//그렇게 정렬되었을 때, 이웃해 있는 노드들의 거리를 엣지로 해서 저장

//근데 지금 생각해보니까
//엄연히 따지면 이게 맞는 방법은 아니네
//왜냐하면, 정렬 했을때 i번째에 있는 노드랑 i+1번째에 있는 노드 간의 거리는
//엄연히 이야기하면 엣지의 weight가 아니지
//weight는 x, y, z 거리 중 최솟값이니까

//그렇지만, 이렇게 했을 때 두 노드에 대해 중복되어 edge들이 만들어진다고 해도
//어차피 길이에 대해 오름차순 정렬하고 나면
//그 중복된 edge 중에서 가장 짧은게 사용되기 때문에
//문제를 푸는 데에는 상관이 없다....ㅎ

//아 참고로 이건 풀이를 찾아보고 풀었다

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
	int nodeNum;
	int x, y, z;
};
struct Edge {
	int node1, node2, weight;
};

vector<Node> nodes;
vector<Edge> edges;
vector<int> root;

bool sortEdges(Edge, Edge);
bool sortbyX(Node, Node);
bool sortbyY(Node, Node);
bool sortbyZ(Node, Node);
int find(int);
void unite(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int cnt;
	long long sum;
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		Node temp;

		temp.nodeNum = i;
		cin >> temp.x >> temp.y >> temp.z;
		nodes.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), sortbyX);
	for (i = 0; i < n - 1; i++) {
		Edge temp;

		temp.node1 = nodes[i].nodeNum;
		temp.node2 = nodes[i + 1].nodeNum;
		temp.weight = nodes[i + 1].x - nodes[i].x;

		edges.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), sortbyY);
	for (i = 0; i < n - 1; i++) {
		Edge temp;

		temp.node1 = nodes[i].nodeNum;
		temp.node2 = nodes[i + 1].nodeNum;
		temp.weight = nodes[i + 1].y - nodes[i].y;

		edges.push_back(temp);
	}

	sort(nodes.begin(), nodes.end(), sortbyZ);
	for (i = 0; i < n - 1; i++) {
		Edge temp;

		temp.node1 = nodes[i].nodeNum;
		temp.node2 = nodes[i + 1].nodeNum;
		temp.weight = nodes[i + 1].z - nodes[i].z;

		edges.push_back(temp);
	}

	sort(edges.begin(), edges.end(), sortEdges);
	cnt = 0;
	sum = 0;
	root.resize(n + 1, -1);
	for (i = 0; i < edges.size() && cnt < n - 1; i++) {
		if (find(edges[i].node1) != find(edges[i].node2)) {
			unite(edges[i].node1, edges[i].node2);
			sum += (long long)edges[i].weight;
			cnt++;
		}
	}

	cout << sum << '\n';

	return 0;
}

bool sortEdges(Edge a, Edge b)
{
	return a.weight < b.weight;
}

bool sortbyX(Node a, Node b)
{
	return a.x < b.x;
}

bool sortbyY(Node a, Node b)
{
	return a.y < b.y;
}
bool sortbyZ(Node a, Node b)
{
	return a.z < b.z;
}

int find(int x)
{
	if (root[x] == -1) {
		return x;
	}
	return root[x] = find(root[x]);
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