#include <iostream>
using namespace std;

int reverseInteger(int a) {
	int ret = 0;
	while (a > 0) {
		ret *= 10;
		ret += a % 10;
		a /= 10;
	}
	return ret;
}

int solution(int a, int b) {
	return reverseInteger(reverseInteger(a) + reverseInteger(b));
}

int main(){
    int a, b; cin >> a >> b;
    cout << solution(a, b);
}
