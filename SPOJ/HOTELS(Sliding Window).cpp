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
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, M, x;
    cin >> N >> M;

    vector<ll> V;
    for (int i = 0; i < N; i++)
        cin >> x, V.push_back(x);

    ll ans = 0, sm = V[0];
    if (sm <= M)
        ans = sm;
    queue<ll> Q;
    Q.push(V[0]);
    for (int i = 1; i < N; i++)
    {
        if (sm + V[i] <= M)
        {
            sm += V[i];
            Q.push(V[i]);
        }
        else
        {
            while (sm + V[i] > M)
            {
                sm -= Q.front();
                Q.pop();
            }
            sm += V[i];
            Q.push(V[i]);
        }
        ans = max(ans, sm);
    }

    cout << ans << endl;

    return 0;
}
// END OF SOURCE CODE