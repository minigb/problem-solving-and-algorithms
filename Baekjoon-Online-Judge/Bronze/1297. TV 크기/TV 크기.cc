#include <iostream>
#include <cmath>

int main()
{
	using namespace std;

	int a, b, c;

	cin >> a >> b >> c;

	cout << (int)(a * b / sqrt(b * b + c * c));
	cout << ' ';
	cout << (int)(a * c / sqrt(b * b + c * c)) << endl;

	return 0;
}