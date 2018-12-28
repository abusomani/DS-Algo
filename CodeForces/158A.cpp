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
        ll N, K, x, ans = 0;
        cin >> N >> K;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);

        for (int i = N - 1; i >= 0; i--)
            if (V[i] >= V[K - 1] and V[i])
                ans++;

        cout << ans;
    }
    return 0;
}
// END OF SOURCE CODE