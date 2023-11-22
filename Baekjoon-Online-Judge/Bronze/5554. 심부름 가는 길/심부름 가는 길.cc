#include <iostream>

int main()
{
    using namespace std;

    int n, sum;
    int i;

    sum = 0;
    for (i = 0; i < 4; i++)
    {
        cin >> n;
        sum += n;
    }

    cout << sum / 60 << endl;
    cout << sum % 60 << endl;

    return 0;
}