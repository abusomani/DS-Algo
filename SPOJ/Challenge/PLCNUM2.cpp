//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

int main()
{
    fastio;
    ll N;
    cin >> N;

    if (N == 1)
        cout << 1 << endl;
    else
    {
        ll arr[N][N];
        memset(arr, 0, sizeof(arr));
        ll cnt = 1;

        for (int i = 0; i < N; i++)
        {
            int l = 0, r = N - 1;
            bool toggle = true;
            while (l <= r)
            {
                if (toggle)
                    arr[i][l++] = cnt++;
                else
                    arr[i][r--] = cnt++;
                toggle = !toggle;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// END OF SOURCE CODE