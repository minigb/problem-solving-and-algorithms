#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i;

	cin >> N;
	vector<int> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}