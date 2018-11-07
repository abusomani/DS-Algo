//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    LONGEST PATH IN AN UNDIRECTED UNWEIGHTED TREE

    LOGIC is using 2 BFS.
    First BFS from any node gives the farthest node. ( true )
    Second BFS from that node gives the longest distance.
    Proof : Assume u to v to be the largest and unique.
    If we have a w such that u to w is longest then in first BFS, w would have been the farthest.

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 100005;
vector<ll> G[MAX_SIZE];
bool visited[MAX_SIZE];

void cleanup()
{
    for (int i = 0; i < MAX_SIZE; i++)
        G[i].clear(), visited[i] = false;
}

pair<ll, ll> BFS(ll src)
{
    memset(visited, false, sizeof(visited));
    ll mx_dist = 0, mx_dist_node = -1; // max distance
    queue<pair<ll, ll>> Q;             // distance and node
    Q.push(make_pair(src, 0));

    while (!Q.empty())
    {
        pair<ll, ll> P = Q.front();
        ll node = P.first;
        ll dist = P.second;
        visited[node] = true;
        for (int i = 0; i < G[node].size(); i++)
        {
            if (!visited[G[node][i]])
            {
                Q.push(make_pair(G[node][i], 1 + dist));
            }
        }
        if (dist > mx_dist)
        {
            mx_dist = dist;
            mx_dist_node = node;
        }
        Q.pop();
    }
    return make_pair(mx_dist, mx_dist_node);
}

int main()
{
    fastio;
    cleanup();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, M, a, b;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    pair<ll, ll> P = BFS(1);
    P = BFS(P.second);

    cout<<P.first<<endl;

    return 0;
}
// END OF SOURCE CODE