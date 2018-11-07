//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    To determine if a cycle exists in a graph. We can use a hack.
    If the graph has a cycle that means there would be atleast one edge such that both its node would have been already added in a set
    Also at end of input of all edges if set size is N, means graph is a tree
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    set<ll> G;
    set<ll>::iterator P1, P2;
    bool isTree = true; // assume its a tree
    ll N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        if (G.find(a) != G.end() and G.find(b) != G.end()) // both nodes have already come, means its a cycle
            isTree = false;
        else
            G.insert(a), G.insert(b);
    }
    if (isTree and G.size() == N) // if no cycle and has all edges between all nodes, completely connected component
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
// END OF SOURCE CODE