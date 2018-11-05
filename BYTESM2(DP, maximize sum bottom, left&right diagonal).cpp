//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    maximize sum from top to bottom, direction of moving below, left/right diagonal
    dp[i][j] = arr[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
    handle boundary cases
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
        ll N, M;
        cin >> N >> M;
        ll arr[N][M], dp[N][M];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> arr[i][j];

        for (int i = 0; i < M; i++)
            dp[0][i] = arr[0][i];
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                ll fromLeft = ((j - 1 >= 0) ? dp[i - 1][j - 1] : 0);
                ll fromRight = ((j + 1 < M) ? dp[i - 1][j + 1] : 0);
                dp[i][j] = arr[i][j] + max(dp[i - 1][j], max(fromLeft, fromRight));
            }
        }

        ll ans = 0;
        for (int i = 0; i < M; i++)
            ans = max(ans, dp[N - 1][i]);

        cout << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE