#include <iostream>

int main()
{
    using namespace std;

    int n, sum;
    int i;

    sum = 0;
    for (i = 0; i < 5; i++)
    {
        cin >> n;
        sum += n;
    }

    cout << sum << endl;

    return 0;
}