#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool notPrime[10000];
vector<int> prime;
vector <int> before = { 2, 3, 5, 7 };

void getPrime();
bool chkPrime(int);
int main()
{
	int n;
	int temp;
	int i, j, k;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	getPrime();

	cin >> n;

	for (k = 1; k < n; k++) {
		vector<int> now;

		for (i = 0; i < before.size(); i++) {
			for (j = 1; j < 10; j += 2) {
				temp = before[i] * 10 + j;
				if (chkPrime(temp)) {
					now.push_back(temp);
				}
			}
		}

		before = now;
	}
	
	for (i = 0; i < before.size(); i++) {
		cout << before[i] << '\n';
	}
	return 0;
}

void getPrime()
{
	int i, j;
	notPrime[1] = 1;
	for (i = 2; i < 10000; i++) {
		if (!notPrime[i]) {
			prime.push_back(i);
			for (j = i * 2; j < 10000; j += i) {
				notPrime[j] = 1;
			}
		}
	}

	return;
}

bool chkPrime(int k)
{
	int temp;
	int i;

	temp = sqrt(k);
	for (i = 0; temp >= prime[i]; i++) {
		if (k % prime[i] == 0) {
			return 0;
		}
	}

	return 1;
}