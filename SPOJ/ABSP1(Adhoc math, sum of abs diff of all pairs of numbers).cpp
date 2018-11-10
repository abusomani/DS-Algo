//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Optimize this :
    int ABS(int a[], int n)
    {
        int sum = 0;
        for (int i = 1; i <= n ;i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                sum += abs(a[i] - a[j]);
            }
        }
    }
    Closely looking we can see, there is a pattern :
    Every number at position i, is added i times and subtracted (N-i-1) times.
    So run a loop with this logic 
*/
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
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        if (N == 0)
            cout << 0 << endl;
        else
        {
            ll arr[N];
            for (int i = 0; i < N; i++)
                cin >> arr[i];
            ll sm = 0;
            for (int i = 0; i < N; i++)
                sm += (arr[i] * (i - (N - i - 1)));
            cout << sm << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE