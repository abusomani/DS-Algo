//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    The question makes us feel to do a BFS from each source. It would TLE.
    Rather than single source, do a multi source BFS which can be done by using modified Dijkstra
    push all source nodes with distance zero and then proceed

    But we can also solve this by DP => Run for each character into the whole array so O(26 * N^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_SIZE = 55;

// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

char arr[MAX_SIZE][MAX_SIZE];
ll dp[MAX_SIZE][MAX_SIZE];
ll N, M;

bool isValid(ll i, ll j)
{
    return ((i >= 1 and i <= N) and (j >= 1 and j <= M));
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll cnt = 0;
    while (true)
    {
        cnt++;
        cin >> N >> M;
        if (!N and !M)
            break;

        ll longest = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                dp[i][j] = -INF;
                cin >> arr[i][j];

                if (arr[i][j] == 'A')
                    dp[i][j] = 1;
            }
        }

        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j++)
                {
                    if (arr[i][j] != ch)
                        continue;

                    for (int k = 0; k < 8; k++)
                    {
                        ll newX = i + rows[k];
                        ll newY = j + cols[k];
                        if (isValid(newX, newY) and (arr[newX][newY] == (ch - 1))) 
                        {
                            dp[i][j] = max(dp[newX][newY] + 1, dp[i][j]);
                        }
                    }
                    
                    longest = max(longest, dp[i][j]);
                }
        }

        cout << "Case " << cnt << ": " << longest << endl;
    }

    return 0;
}
// END OF SOURCE CODE