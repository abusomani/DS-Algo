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
    ll T;
    T = 1;
    while (T--)
    {
        ll N, K, S, x;
        cin >> N >> K >> S;
        ll val = K * S;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);
        sort(V.rbegin(), V.rend());

        ll sm = 0;
        for (int i = 0; i < N; i++)
        {
            sm += V[i];
            if (sm >= val)
            {
                cout << i + 1;
                break;
            }
        }
    }
    return 0;
}
// END OF SOURCE CODE