//하 씨발...
//ㅈ을 구하는 건 금방 했다. nC3
//근데 ㄷ 구할때...
//4개의 노드가 이어진 것의 개수를 찾으려고 해서
//처음엔 모든 정점에 대해서 BFS 돌리다가
//(어쩌면 당연하게도) 시간초과가 나서
//DFS로 바꿨는데 그것도 뭐 당연하게도 시간초과
//그래서 adj[i].size()==1인 노드만 체크하도록 해봤는데
//(간선이 쭉 이어질 때, 그 양 끝만 체크하도록)
//visited를 처리하고 하는 게 좀 복잡했다

//그래서 결국 답지를 봤다 슈밤
//그랬더니 생각보다 간단했어
//ㅠㅠㅠㅠㅠㅠㅠㅠ
//왜 이런 생각을 못 했을까...
//간선이 4개, 5개가 아니라 3개인 데는 무조건 이유가 있었을텐데...
//출제자의 의도를 파악하지 못했네

//출제자의 의도를 파악하지 못했어...
//이게 진짜 중요할 거 같다 앞으로도

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	long long cntD, cntG;
	long long size;
	int next;
	int temp, temp2;
	int i, j;

	cin >> n;
	adj.resize(n + 1);
	for (i = 0; i < n - 1; i++) {
		cin >> temp >> temp2;
		adj[temp].push_back(temp2);
		adj[temp2].push_back(temp);
	}

	//ㅈ 세기
	cntG = 0;
	for (i = 1; i <= n; i++) {
		size = (long long)adj[i].size();
		if (size >= 3) {
			cntG += size * (size - 1) / 2 * (size - 2) / 3;
		}
	}

	//ㄷ세기
	cntD = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < adj[i].size(); j++) {
			next = adj[i][j];
			if (i > next) {
				continue;
			}
			cntD += (long long)(adj[i].size() - 1) * (adj[next].size() - 1);
		}
	}

	if (cntD > 3 * cntG) {
		cout << "D" << '\n';
	}
	else if (cntD < 3 * cntG) {
		cout << "G" << '\n';
	}
	else {
		cout << "DUDUDUNGA" << '\n';
	}

	return 0;
}