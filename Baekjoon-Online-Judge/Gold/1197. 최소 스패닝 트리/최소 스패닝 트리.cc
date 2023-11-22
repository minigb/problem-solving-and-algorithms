#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#define kEndl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

typedef struct edge {
	int node1, node2;
	ll cost;

	edge() {}
	edge(int node1, int node2, ll cost) {
		this->node1 = node1;
		this->node2 = node2;
		this->cost = cost;
	}

	bool operator< (edge comp) const {
		if (cost != comp.cost) {
			return cost < comp.cost;
		}
	}
	bool operator> (edge comp) const {
		return cost > comp.cost;
	}
} Edge;

template<typename T>
class Heap {
public:
	Heap<T>() {
		end = 1;
		tree.resize(1);
	}

	virtual void push(T value) = 0;
	virtual void pop() = 0;

	T top() {
		return tree[1];
	}

	bool empty() {
		return end == 1;
	}

	ull size() {
		return end;
	}

protected:
	vector<T> tree;
	ull end;
};

template<typename T>
class MinHeap : public Heap<T> {
public:
	virtual void push(T value) {
		if (this->end == this->tree.size()) {
			this->tree.resize(this->tree.size() * 2);
		}
		this->tree[this->end++] = value;

		for (ull child = this->end - 1; child >= 1; child /= 2) {
			ull parent = child / 2;
			if (parent >= 1 && this->tree[parent] > this->tree[child]) {
				swap(this->tree[parent], this->tree[child]);
			}
			else {
				break;
			}
		}
	}

	virtual void pop() {
		this->tree[1] = this->tree[this->end - 1];
		this->end--;

		for (ull parent = 1; parent * 2 < this->end; ) {
			ull smallerChild;
			if (parent * 2 + 1 < this->end) {
				smallerChild = parent * 2 + (this->tree[parent * 2] < this->tree[parent * 2 + 1] ? 0 : 1);
			}
			else {
				smallerChild = parent * 2;
			}

			if (this->tree[smallerChild] < this->tree[parent]) {
				swap(this->tree[parent], this->tree[smallerChild]);
				parent = smallerChild;
			}
			else {
				break;
			}
		}
	}
};

class UnionFind {
public:
	void Init(int n) {
		this->n = n;
		parent.resize(n, -1);
	}

	int GetParent(int a) {
		if (parent[a] == -1) {
			return a;
		}
		return parent[a] = GetParent(parent[a]);
	}

	void Merge(int a, int b) {
		a = GetParent(a);
		b = GetParent(b);
		if (a != b) {
			parent[a] = b;
		}
	}

protected:
	int n;
	vector<int> parent;
};

class MST {
public:
	MST(int n, int e) {
		++n;
		this->n = n;
		this->e = e;
		uf.Init(n);
	}

	void MakeEdge(int node1, int node2, ll cost) {
		min_heap.push(Edge(node1, node2, cost));
	}

	const vector<Edge>& GetMST() {
		if (count != 0) {
			return mst_edges;
		}

		while (!min_heap.empty() && count < n - 1) {
			Edge current = min_heap.top();
			min_heap.pop();

			if (uf.GetParent(current.node1) != uf.GetParent(current.node2)) {
				mst_edges.push_back(current);
				uf.Merge(current.node1, current.node2);
				total_cost += current.cost;
				++count;
			}
		}
		sort(mst_edges.begin(), mst_edges.end());
		connected = (count == n - 1);

		return mst_edges;
	}

	ll GetTotalCost() const {
		return total_cost;
	}

	bool IsConnected() const {
		return connected;
	}

protected:
	int n = 0, e = 0; //number of nodes, edges
	ll total_cost = 0;
	int count = 0;
	UnionFind uf; //for union-find
	MinHeap<Edge> min_heap; //for mst
	vector<Edge> mst_edges;
	bool connected;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, e; cin >> n >> e;
	MST mst(n, e);
	for (int i = 0; i < e; ++i) {
		int node1, node2; cin >> node1 >> node2;
		ll cost; cin >> cost;
		mst.MakeEdge(node1, node2, cost);
	}

	mst.GetMST();
	cout << mst.GetTotalCost() << kEndl;
}