//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    The question makes us feel to do a BFS from each source. It would TLE.
    Rather than single source, do a multi source BFS which can be done by using modified Dijkstra
    push all source nodes with distance zero and then proceed
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
ll dist[MAX_SIZE][MAX_SIZE];
ll N, M;
 
bool isValid(ll i, ll j)
{
    return ((i >= 1 and i <= N) and (j >= 1 and j <= M));
}
 
ll dijkstra(vector<pll> &Sources)
{
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> PQ;
    for (int i = 0; i < Sources.size(); i++)
    {
        pll P = Sources[i];
        PQ.push({dist[P.first][P.second], P});
    }
 
    ll longestPath = 0;
 
    while (!PQ.empty())
    {
        pll node = PQ.top().second;
        ll dis = PQ.top().first;
 
        PQ.pop();
 
        for (int K = 0; K < 8; K++)
        {
            ll i = node.first + rows[K];
            ll j = node.second + cols[K];
            if (isValid(i, j))
            {
                if (arr[i][j] == (arr[node.first][node.second] + 1))
                {
                    if (dist[i][j] < dist[node.first][node.second] + 1)
                    {
                        dist[i][j] = dist[node.first][node.second] + 1;
                        PQ.push({dist[i][j], {i, j}});
                    }
                }
            }
        }
 
        longestPath = max(longestPath, dis);
    }
    return longestPath;
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
 
        vector<pll> V;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
            {
                dist[i][j] = 0;
                cin >> arr[i][j];
                if (arr[i][j] == 'A')
                    dist[i][j] = 1, V.push_back({i, j});
            }
 
        cout << "Case " << cnt << ": " << dijkstra(V) << endl;
    }
 
    return 0;
}
// END OF SOURCE CODE 