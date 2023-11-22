#include <iostream>
using namespace std;

int main()
{
	int t1, t2;
	long long cnt;
	int temp;

	cin >> t1 >> t2;
	cnt = 2;
	while (t1 >= t2) {
		cnt++;
		temp = t1 - t2;
		t1 = t2;
		t2 = temp;
	}

	cout << cnt << endl;

	return 0;
}