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
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};
const ll MAX = 100005;
ll dp[MAX];
ll arr[MAX];

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        ll N, K, x;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            arr[x]++;
        }

        dp[1] = arr[1];

        for (int i = 2; i < MAX - 1; i++)
        {
            dp[i] = max((i * arr[i]) + dp[i - 2], dp[i - 1]);
        }
        dp[MAX - 1] = max((MAX - 1) * arr[MAX - 1] + dp[MAX - 3], dp[MAX - 2]);
        cout << dp[MAX - 1] << endl;
    }
    return 0;
}
// END OF SOURCE CODE