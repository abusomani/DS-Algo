//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Simple dp by making [0][0] node to be 0 and [0][1] to be arr[0][1]
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

// 4 directions as needed in the problem
const ll rows[] = {0, 1, 1, 1};
const ll cols[] = {1, 1, 0, -1};

const ll MAX_SIZE = 100005;

ll dp[MAX_SIZE][3];
ll arr[MAX_SIZE][3];

bool isValid(ll i, ll j, ll N)
{
    return ((i >= 0 and i < N) and (j >= 0 and j < 3));
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T = 0;
    while (true)
    {
        T++;
        ll N, K, x;
        cin >> N;
        if (!N)
            break;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 3; j++)
                cin >> arr[i][j], dp[i][j] = INF;

        dp[0][0] = 0;         // no use of this node
        dp[0][1] = arr[0][1]; // Source node

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 0 and j == 0)
                    continue;

                for (int k = 0; k < 4; k++)
                {
                    ll newX = i + rows[k];
                    ll newY = j + cols[k];
                    if (isValid(newX, newY, N))
                    {
                        dp[newX][newY] = min(dp[newX][newY], dp[i][j] + arr[newX][newY]);
                    }
                }
            }
        }
        cout << T << ". " << dp[N - 1][1] << endl;
    }
    return 0;
}
// END OF SOURCE CODE