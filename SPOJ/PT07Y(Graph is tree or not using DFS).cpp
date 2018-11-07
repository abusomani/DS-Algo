//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    To determine if a cycle exists in a graph. Use normal dfs by passing the node in the call as parent.
    If we encounter an already visited node ( back-edge ) then its cycle because
    in the dfs, make a call only if the going to visit node is different from parent.
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
bool isTree;

void DFS(ll src, ll parent) // modified for cycle identification
{
    // if we encounter an already visited node that means there is a cycle
    if (visited[src])
    {
        isTree = false;
        return;
    }

    visited[src] = true;

    for (int i = 0; i < G[src].size(); i++)
    {
        ll node = G[src][i];
        if (node != parent) // Only call dfs if the neighbour node is not the parent who
            DFS(node, src);
    }
}

void cleanup()
{
    for (int i = 0; i < MAX_SIZE; i++)
        visited[i] = false, G[i].clear();
    isTree = true;
}

int main()
{
    fastio;
    cleanup();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    DFS(1, 1);
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            isTree = false;
    if (isTree)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
// END OF SOURCE CODE