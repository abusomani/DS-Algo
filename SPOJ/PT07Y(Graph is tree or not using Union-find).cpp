//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    To determine if a cycle exists in a graph. We can use union find for dynamic connectivity
    In union just check if any node has size equal to total nodes, means complete connectivity
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
ll id[MAX_SIZE];
ll sz[MAX_SIZE];
bool isTree, isCompletelyConnected;

void cleanup()
{
    isTree = true;
    isCompletelyConnected = false;
    for (int i = 0; i < MAX_SIZE; i++)
        id[i] = i, sz[i] = 1;
}

ll find(ll a)
{
    ll parent = id[a];
    while (parent != id[parent])
    {
        id[parent] = id[id[parent]]; // PATH COMPRESSION
        parent = id[parent];
    }
    return parent;
}

void unite(ll a, ll b, ll N)
{
    ll parentOfA = find(a), parentOfB = find(b);
    if (sz[parentOfA] < sz[parentOfB])
    {
        id[parentOfA] = id[parentOfB];
        sz[parentOfB] += sz[parentOfA];
    }
    else
    {
        id[parentOfB] = id[parentOfA];
        sz[parentOfA] += sz[parentOfB];
    }
    if (sz[parentOfA] == N or sz[parentOfB] == N)
        isCompletelyConnected = true;
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
        if (find(a) == find(b))
            isTree = false;
        else
            unite(a, b, N);
    }
    if (isTree and isCompletelyConnected) // if no cycle and has all edges between all nodes, completely connected component
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
// END OF SOURCE CODE