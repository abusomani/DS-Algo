//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Bipartite graph checking
    Only use color array and not visited
    0 for unassigned , 1 for male, -1 for female

    loop through all components (if unassigned call dfs) LINE : 75

    in DFS, have a local variable set to true
    if color is present, check if it is equal to src node. if yes return false
    if color is not assigned, assign the negative of color[src] and the result is ANDed with local bool variable
    
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define Male 1       //male
#define Female (-1)  //female
#define Unassigned 0 // unassigned

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 2005;

vector<ll> G[MAX_SIZE];
ll color[MAX_SIZE];

void cleanup()
{
    for (int i = 0; i < MAX_SIZE; i++)
        G[i].clear(), color[i] = Unassigned;
}

bool isBipartite(ll src)
{
    bool res = true; // for final result
    for (int i = 0; i < G[src].size(); i++)
    {
        ll node = G[src][i];
        if (color[node] == color[src]) // if color is assigned and is equal to color of parent means not Bipartite
            return false;
        if (color[node] == Unassigned) // call DFS only if color is not assigned by negating the color of present node from the parent
        {
            color[node] = -color[src];
            res = res and isBipartite(node);
        }
    }
    return res; // if traversed whole component
}

int main()
{
    fastio;
    ll T, cnt = 0;
    cin >> T;
    while (T--)
    {
        cnt++;
        cleanup();
        ll N, M, K, x, y;
        cin >> N >> M;

        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        bool isTwoColorable = true;

        // for all components do a DFS
        for (int i = 1; i <= N; i++)
        {
            if (color[i] == Unassigned)
            {
                color[i] = Male;
                isTwoColorable = isTwoColorable and isBipartite(i);
            }
        }

        cout << "Scenario #" << cnt << ":" << endl;
        if (isTwoColorable)
            cout << "No suspicious bugs found!" << endl;
        else
            cout << "Suspicious bugs found!" << endl;
    }
    return 0;
}
// END OF SOURCE CODE