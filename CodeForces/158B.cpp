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
        cin >> N;
        map<ll, ll> Mp;

        for (int i = 1; i <= 4; i++)
            Mp[i] = 0;

        for (int i = 0; i < N; i++)
            cin >> x, Mp[x]++;

        ans += Mp[4];       // one car for each group of size
        if (Mp[3] >= Mp[1]) // three will merge with ones, so by any means Mp[3] would be counted
        {
            ans += Mp[3];
            Mp[1] = 0;
        }
        else
        {
            ans += Mp[3];
            Mp[1] -= Mp[3];
        }

        if (2 * Mp[2] >= Mp[1])
        {
            ll onePair = (Mp[1] + 1) / 2;
            ans += onePair;
            Mp[2] -= onePair;
            ans += ((Mp[2] + 1) / 2);
        }
        else
        {
            ans += Mp[2];
            Mp[1] -= 2 * Mp[2];
            ans += (Mp[1] / 4);
            if (Mp[1] % 4)
                ans++;
        }

        cout << ans;
    }
    return 0;
}
// END OF SOURCE CODE