//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    EDIT DISTANCE :
    Dp problem, (Example : hello yellow) [0..i] to [0..j]

    if m == 0 return n; // n insertions
    if n == 0 return m; // m insertions
    if a[n-1] == b[m-1]  // if same character
        return f(n-1,m-1)
    else
        1 + min(
            f(m,n-1), // insert into first
            f(m-1,n), // remove from first
            f(m-1.n-1) // replace
        )
*/
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

ll editDistRecur(string a, string b, ll N, ll M)
{
    if (N == 0)
        return M;
    if (M == 0)
        return N;

    if (a[N - 1] == b[M - 1])
        return editDistRecur(a, b, N - 1, M - 1);

    else
        return (1 + min(editDistRecur(a, b, N, M - 1), min(editDistRecur(a, b, N - 1, M), editDistRecur(a, b, N - 1, M - 1))));
}

ll editDistDP(string a, string b)
{
    ll dp[a.size() + 1][b.size() + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= a.size(); i++)
        dp[i][0] = i;
    for (int i = 0; i <= b.size(); i++)
        dp[0][i] = i;

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    // PRINTING and DEBUGGING
    // for (int i = 0; i <= b.size(); i++)
    //     if (i == 0)
    //         cout << "   ";
    //     else
    //         cout << b[i - 1] << " ";
    // cout << endl;
    // for (int i = 0; i <= a.size(); i++)
    // {
    //     if (i == 0)
    //         cout << " ";
    //     else
    //         cout << a[i - 1] << " ";
    //     for (int j = 0; j <= b.size(); j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return dp[a.size()][b.size()];
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
        string a, b;
        cin >> a >> b;
        cout << editDistDP(a, b) << endl;
    }
    return 0;
}
// END OF SOURCE CODE