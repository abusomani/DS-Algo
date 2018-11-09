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
const ll MAX_SIZE = 100005;

vector<pair<ll, ll>> G[MAX_SIZE];
bool visited[MAX_SIZE];
ll dist[MAX_SIZE];

void preprocess()
{
    for (int i = 0; i < MAX_SIZE; i++)
        visited[i] = false, dist[i] = INF, G[i].clear();
}

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    dist[src] = 0;
    PQ.push({dist[src], src});

    while (!PQ.empty())
    {
        ll node = PQ.top().second;
        PQ.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        for (int i = 0; i < G[node].size(); i++)
        {
            ll to = G[node][i].first;
            ll cost = G[node][i].second;

            //relaxation
            if (dist[to] > dist[node] + cost)
            {
                dist[to] = dist[node] + cost;
                PQ.push({dist[to], to});
            }
        }
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
        preprocess();
        ll N, M, Src, Dest, K, a, b, c;
        cin >> N >> M >> Src >> Dest;
        while (M--)
        {
            cin >> a >> b >> c;
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }
        dijkstra(Src);

        if (dist[Dest] == INF)
            cout << "NONE" << endl;
        else
            cout << dist[Dest] << endl;
    }
    return 0;
}
// END OF SOURCE CODE