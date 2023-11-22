#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> Primes;
vector<bool> isPrime;
vector<bool> isDivisable;

int main()
{
	long long min, max;
	long long sqrt_max;
	long long cur;
	int cnt;
	long long prime2;
	long long i, j;

	cin >> min >> max;

	sqrt_max = (long long)sqrt(max);
	isPrime.resize(sqrt_max + 2, 1);
	for (i = 2; i <= sqrt_max + 1; i++) {
		if (isPrime[i]) {
			Primes.push_back(i);
			for (j = i * 2; j <= sqrt_max + 1; j += i) {
				isPrime[j] = 0;
			}
		}
	}

	cnt = max - min + 1;
	isDivisable.resize(max - min + 1); //min은 0번에, min+1은 1번에...
	for (long long prime : Primes) {
		if (min % (prime*prime) == 0 && !isDivisable[0]) {
			isDivisable[0] = 1;
			cnt--;
		}

		prime2 = prime * prime;
		for (i = (min / prime2 + 1) * prime2; i <= max; i += prime2) {
			if (!isDivisable[i - min]) {
				isDivisable[i - min] = 1;
				cnt--;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}