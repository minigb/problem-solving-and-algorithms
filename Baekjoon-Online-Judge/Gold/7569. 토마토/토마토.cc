//약 40분
//왜 이렇게 오래 걸렸냐면...

//처음에는 변수를 k, i, j 이렇게 쓰는 게 싫어서
//i[3]을 만들고 그걸 반복을 위한 배열로 사용하려고 했는데
//너무 코드가 눈에 안 들어와서
//다시 k, i, j로 바꿈

//그리고 처음에 -1로 초기화 할 때
//상자 안의 내용은 입력으로 받으니까
//겉 테두리만 초기화하도록 했는데
//그게 왜 때문인지 잘 안 됐다
//그래서 그냥 모든 영역을 다 초기화하는걸로 바꿈

//그리고 영역이 1부터 h, m, n까지인데
//막판에 습관처럼 0부터 h, m, n의 미만으로 해서
//또 답이 안 나왔다...

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[102][102][102];

int main()
{
	int n, m, h;
	queue<int> que[3];
	int dir[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
	int ans;
	int i, j, k, s;

	for (k = 0; k <= 101; k++) {
		for (i = 0; i <= 101; i++) {
			for (j = 0; j <= 101; j++) {
				a[k][i][j] = -1;
			}
		}
	}

	cin >> n >> m >> h;

	
	
	for (k = 1; k <= h; k++) {
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				cin >> a[k][i][j];
				if (a[k][i][j] == 1) {
					que[0].push(k);
					que[1].push(i);
					que[2].push(j);
				}
			}
		}
	}

	while (!que[0].empty()) {
		k = que[0].front();
		que[0].pop();
		i = que[1].front();
		que[1].pop();
		j = que[2].front();
		que[2].pop();

		for (s = 0; s < 6; s++) {
			if (a[k + dir[s][0]][i + dir[s][1]][j + dir[s][2]] == 0) {
				a[k + dir[s][0]][i + dir[s][1]][j + dir[s][2]] = a[k][i][j] + 1;
				
				que[0].push(k + dir[s][0]);
				que[1].push(i + dir[s][1]);
				que[2].push(j + dir[s][2]);
			}
		}
	}

	ans = 0;
	for (k = 1; k <= h; k++) {
		for (i = 1; i <= m; i++) {
			for (j = 1; j <= n; j++) {
				if (ans == -1) {
					continue;
				}
				
				if (a[k][i][j] == 0) {
					ans = -1;
				}
				else if(a[k][i][j] > 1) {
					ans = max(ans, a[k][i][j] - 1);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}