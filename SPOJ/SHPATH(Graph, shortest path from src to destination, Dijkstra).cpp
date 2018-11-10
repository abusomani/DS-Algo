//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Dijkstra's algorithm :
    Vertex based.
    Source vertex distance is zero, rest is infinity
    Use priority_queue ( PQ is default MAX Heap) so make it Min Heap by
    priority_queue < int, vector<int> , greater<int> >
    Push {distance, node} in PQ and store visited, and distance

    Running complexity = ElogV
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
const ll MAX_SIZE = 10005;

vector<pair<ll, ll>> G[MAX_SIZE]; // Adjacency list contains, to which node present node is connected and the cost for it
bool visited[MAX_SIZE];
ll dist[MAX_SIZE];

void clearGraph()
{
    for (int i = 0; i < MAX_SIZE; i++)
        G[i].clear();
}

void preprocess()
{
    for (int i = 0; i < MAX_SIZE; i++)
        visited[i] = false, dist[i] = INF;
}

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> PQ; // Min heap, where pair<ll,ll> is {Distance , node};
    dist[src] = 0;
    PQ.push({dist[src], src});

    while (!PQ.empty())
    {
        ll node = PQ.top().second;
        PQ.pop();

        if (visited[node]) // if visited that means already shortest path till this vertex is computed
            continue;

        visited[node] = true;

        for (int i = 0; i < G[node].size(); i++) // Traverse the adjacency list
        {
            ll toNode = G[node][i].first;
            ll costToNode = G[node][i].second;
            // RELAXATION step of Dijkstra (heart and core)
            if (dist[toNode] > dist[node] + costToNode)
            {
                dist[toNode] = dist[node] + costToNode;
                PQ.push({dist[toNode], toNode});
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
        clearGraph();
        ll N, numberOfNeighbors, b, c; // N nodes
        cin >> N;

        string cityName;
        map<string, ll> Mp;
        for (int i = 1; i <= N; i++)
        {
            cin >> cityName;
            Mp.insert({cityName, i});
            cin >> numberOfNeighbors;
            while (numberOfNeighbors--)
            {
                cin >> b >> c;
                G[i].push_back({b, c});
                G[b].push_back({i, c});
            }
        }

        string from, to;
        ll Q;
        cin >> Q;
        while (Q--)
        {
            cin >> from >> to;
            preprocess();
            dijkstra(Mp[from]);
            cout << dist[Mp[to]] << endl;
        }
    }

    return 0;
}
// END OF SOURCE CODE