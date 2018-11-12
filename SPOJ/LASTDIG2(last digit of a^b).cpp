#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastPow(ll a, ll b, ll MOD)
{
    ll ans = 1, x = a;

    while (b)
    {
        if (b & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        string s;
        ll b;
        cin >> s;
        cin >> b;

        ll a = (ll)(s[s.size() - 1] - '0');
        cout << fastPow(a, b, 10) << endl;
    }
    return 0;
}