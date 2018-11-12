//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    So it is a recursion of  return max(arr[i] + f(i+2), f(i+1))
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
    ll T, cnt = 0;
    cin >> T;
    while (T--)
    {
        cnt++;
        ll N, K, x;
        cin >> N;
        ll arr[N], dp[N + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        dp[0] = arr[0];              // if one element it is the max
        dp[1] = max(arr[0], arr[1]); // if two element, it is max of the two numbers

        for (int i = 2; i < N; i++)
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]); // if ith is included then arr[i] + answer till (i-2) else answer till (i-1)
        if (N)
            cout << "Case " << cnt << ": " << dp[N - 1] << endl;
        else
            cout << "Case " << cnt << ": " << 0 << endl;
    }
    return 0;
}
// END OF SOURCE CODE