#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int cur;
	int left, right, mid;
	int i;

	while (cin >> n) {
		vector<int> lis(1, 0);

		for (i = 0; i < n; i++) {
			cin >> cur;

			if (lis.back() < cur) {
				lis.push_back(cur);
				continue;
			}

			left = 1;
			right = lis.size();
			while (left < right) {
				if (left + 1 == right) {
					lis[left] = cur;
					break;
				}

				mid = (left + right) / 2;

				if (lis[mid] == cur) {
					break;
				}

				else if (cur < lis[mid]) {
					if (lis[mid - 1] < cur) {
						lis[mid] = cur;
						break;
					}
					else {
						right = mid;
					}
				}

				else {
					left = mid + 1;
				}
			}
		}

		cout << lis.size() - 1 << '\n';
	}
	return 0;
}