//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Adding one edge and doing dijkstra again and again will cause TLE
    So if we think deeply,
    do a dijkstra from src and store it in one array let say DistFromSource
    do a dijkstra from dest and store it in let say DistFromDest ( needs a reverse graph as well)

    the distance from src to dest without adding any edge would be DistFromSource

    now adding a bidirectional edge, lets assume it is on the shortest path,
    but the total answer would be
    Bidirectional edge being added is  (u, v, cost)
    min (DistFromSource[Dest],  DistFromSource[u] + cost + DistFromTarget[v] ,  DistFromSource[v] + cost + DistFromTarget[u])
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f;
const ll MAX_SIZE = 10005;

vector<vector<pair<ll, ll>>> G;
vector<vector<pair<ll, ll>>> RG;
vector<ll> DistFromSource(MAX_SIZE, INF);
vector<ll> DistFromDest(MAX_SIZE, INF);

void dijkstra(ll src, vector<ll> &dist, vector<vector<pair<ll, ll>>> &G)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ;
    dist[src] = 0;
    PQ.push({dist[src], src});

    while (!PQ.empty())
    {
        ll node = PQ.top().second;
        PQ.pop();

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
        DistFromDest = vector<ll>(MAX_SIZE, INF);
        DistFromSource = vector<ll>(MAX_SIZE, INF);

        ll N, M, Src, Dest, K, a, b, c;
        cin >> N >> M >> K >> Src >> Dest;

        G = vector<vector<pair<ll, ll>>>(N + 1, vector<pair<ll, ll>>()); // INITIALIZE
        RG = vector<vector<pair<ll, ll>>>(N + 1, vector<pair<ll, ll>>());

        while (M--)
        {
            cin >> a >> b >> c;
            G[a].push_back({b, c});
            RG[b].push_back({a, c});
        }
        dijkstra(Src, DistFromSource, G); // one dijkstra from source to all with graph
        dijkstra(Dest, DistFromDest, RG); // one dijkstra from dest to all with reverse graph

        ll ans = DistFromSource[Dest]; // without adding bidirectional edge the answer
        while (K--)
        {
            cin >> a >> b >> c;

            // min ( ans without extra edge, min(distance from source to a + cost of edge + distance from dest to b using reverse graph,
            // min(distance from source to b + cost of edge + distance from dest to a using reverse graph))
            ans = min(ans, min(DistFromSource[a] + c + DistFromDest[b], DistFromSource[b] + c + DistFromDest[a]));
        }

        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE