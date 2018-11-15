//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Topological Sort : Kahn's algorithm for DAG.
    Compute indegree and use priority queue
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
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};
const ll MAX_SIZE = 105;

vector<ll> G[MAX_SIZE];
ll indegree[MAX_SIZE];
bool visited[MAX_SIZE];
ll N, M;

void TopologicalSort()
{
    memset(visited, false, sizeof(visited));
    priority_queue<ll, vector<ll>, greater<ll>> PQ;
    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0)
            PQ.push(i);

    while (!PQ.empty())
    {
        ll node = PQ.top();
        PQ.pop();
        visited[node] = true;

        cout << node << " ";

        for (int i = 0; i < G[node].size(); i++)
        {
            ll x = G[node][i];
            indegree[x]--;
            if (indegree[x] == 0 and !visited[x])
                PQ.push(x);
        }
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        ll x, y, n;
        cin >> N >> M;
        while (M--)
        {
            cin >> x >> n;
            while (n--)
            {
                cin >> y; // x is dependent on y, so directed edge from y to x
                G[y].push_back(x);
                indegree[x]++;
            }
        }
        TopologicalSort();
    }
    return 0;
}
// END OF SOURCE CODE