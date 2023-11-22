#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 2000000000;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    int max_sum[3], min_sum[3], temp[3];
    int a, b, c;
    int i;

    cin >> N;
    cin >> a >> b >> c;
    max_sum[0] = min_sum[0] = a;
    max_sum[1] = min_sum[1] = b;
    max_sum[2] = min_sum[2] = c;
    for (i = 1; i < N; i++) {
        cin >> a >> b >> c;

        temp[0] = a + max(max_sum[0], max_sum[1]);
        temp[1] = b + max(max_sum[0], max(max_sum[1], max_sum[2]));
        temp[2] = c + max(max_sum[1], max_sum[2]);
        for (int j = 0; j < 3; j++) {
            max_sum[j] = temp[j];
        }

        temp[0] = a + min(min_sum[0], min_sum[1]);
        temp[1] = b + min(min_sum[0], min(min_sum[1], min_sum[2]));
        temp[2] = c + min(min_sum[1], min_sum[2]);
        for (int j = 0; j < 3; j++) {
            min_sum[j] = temp[j];
        }
    }

    cout << max(max_sum[0], max(max_sum[1], max_sum[2])) << ' ' << min(min_sum[0], min(min_sum[1], min_sum[2])) << '\n';

    return 0;
}