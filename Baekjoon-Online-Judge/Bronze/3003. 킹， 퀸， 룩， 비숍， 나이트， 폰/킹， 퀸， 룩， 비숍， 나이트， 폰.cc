#include <iostream>

int main()
{
    using namespace std;

    int a[6] = { 1, 1, 2, 2 ,2 ,8 };
    int n;
    int i;

    for (i = 0; i < 6; i++)
    {
        cin >> n;
        cout << a[i] - n << ' ';
    }

    cout << endl;
    
    return 0;
}