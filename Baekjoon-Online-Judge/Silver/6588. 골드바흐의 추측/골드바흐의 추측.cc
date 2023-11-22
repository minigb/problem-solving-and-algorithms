#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000

vector<int> primeNums;
vector<bool> isPrime(MAX + 1, true);
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int a, b, c, d;
	int i, j;

	
	isPrime[0] = isPrime[1] = false;
	for (i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			primeNums.push_back(i);
			for (j = i * 2; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	while (1) {
		cin >> N;
		if (!N) {
			break;
		}

		for (int num : primeNums) {
			if (isPrime[N - num]) {
				a = num;
				b = N - num;
				break;
			}
		}
		for (i = lower_bound(primeNums.begin(), primeNums.end(), N) - primeNums.begin() - 1; i; i--) {
			if (isPrime[N - primeNums[i]]) {
				c = N - primeNums[i];
				d = primeNums[i];
				break;
			}
		}

		if (b - a > d - c) {
			cout << N << " = " << a << " + " << b << '\n';
		}
		else {
			cout << N << " = " << c << " + " << d << '\n';
		}
	}

	return 0;
}