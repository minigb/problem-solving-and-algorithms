#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	vector<int> arr;
	vector<int> lis;
	int i;

	cin >> N;
	arr.resize(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	lis.push_back(arr[0]);
	for (i = 1; i < N; i++) {
		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			*upper_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
		}
	}

	cout << lis.size() << '\n';

	return 0;
}