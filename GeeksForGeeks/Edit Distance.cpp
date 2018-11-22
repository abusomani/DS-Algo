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
const ll MAX_SIZE = 105;
ll dp[MAX_SIZE][MAX_SIZE];

string A, B;

ll editDist(ll i, ll j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0) // if first sting is empty
        return dp[i][j] = j;

    if (j == 0) // if second string is empty
        return dp[i][j] = i;
        
    if (A[i - 1] == B[j - 1])
        return dp[i][j] = editDist(i - 1, j - 1);
    return dp[i][j] = 1 + min(editDist(i - 1, j), min(editDist(i - 1, j - 1), editDist(i, j - 1)));
}

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
        cin >> A >> B;
        memset(dp, -1, sizeof(dp));
        editDist(N, M);
        cout << dp[N][M] << endl;
    }
    return 0;
}
// END OF SOURCE CODE