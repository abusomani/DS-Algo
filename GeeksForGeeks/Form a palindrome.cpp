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
const ll MAX_SIZE = 55;
string A;
ll dp[MAX_SIZE][MAX_SIZE];

ll minInsertToPalin(ll i, ll j)
{
    if (i > j)
        return dp[i][j] = 0;
    if (i == j) // one character is always a palindrome
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (A[i] == A[j])
        return dp[i][j] = minInsertToPalin(i + 1, j - 1);
    return dp[i][j] = 1 + min(minInsertToPalin(i, j - 1), minInsertToPalin(i + 1, j));
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
        cin >> A;
        memset(dp, -1, sizeof(dp));
        minInsertToPalin(0, A.size() - 1);
        cout << dp[0][A.size() - 1] << endl;
    }
    return 0;
}
// END OF SOURCE CODE