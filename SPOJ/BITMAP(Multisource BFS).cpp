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
const ll rows[] = {1, -1, 0, 0};
const ll cols[] = {0, 0, 1, -1};

string arr[182];
ll ans[182][182];
queue<pair<int, int>> q;

bool isValid(int x, int y, int R, int C)
{
    return (x >= 0 && y >= 0 && x < R && y < C);
}

void solve(ll R, ll C)
{
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == '1')
            {
                q.push(make_pair(i, j));
                ans[i][j] = 0;
            }
        }
    }

    int time = 1;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            if (isValid(p.first - 1, p.second, R, C) && ans[p.first - 1][p.second] == -1)
            {
                q.push(make_pair(p.first - 1, p.second));
                ans[p.first - 1][p.second] = time;
            }
            if (isValid(p.first + 1, p.second, R, C) && ans[p.first + 1][p.second] == -1)
            {
                q.push(make_pair(p.first + 1, p.second));
                ans[p.first + 1][p.second] = time;
            }
            if (isValid(p.first, p.second - 1, R, C) && ans[p.first][p.second - 1] == -1)
            {
                q.push(make_pair(p.first, p.second - 1));
                ans[p.first][p.second - 1] = time;
            }
            if (isValid(p.first, p.second + 1, R, C) && ans[p.first][p.second + 1] == -1)
            {
                q.push(make_pair(p.first, p.second + 1));
                ans[p.first][p.second + 1] = time;
            }
        }
        time++;
    }
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
        ll N, M, K, x;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                ans[i][j] = INF;

        solve(N, M);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE