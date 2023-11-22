#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	int N;
	int arr[41][2]{};
	int i;

	arr[0][0] = 1;
	arr[1][1] = 1;
	for (i = 2; i <= 40; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}

	cin >> T;
	while (T--) {
		cin >> N;

		cout << arr[N][0] << ' ' << arr[N][1] << '\n';
	}

	return 0;
}