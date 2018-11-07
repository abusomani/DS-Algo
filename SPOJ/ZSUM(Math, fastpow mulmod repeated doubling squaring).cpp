//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 10000007;

// (a*b) by repeated doubling
ll mulMod(ll a, ll b)
{
    ll ans = 0, x = a % MOD;
    while (b)
    {
        if (b & 1)
            ans = (ans + x) % MOD;
        x = (x + x) % MOD;
        b >>= 1;
    }
    return ans;
}

// (a^b) is a power binary representation of b
ll fastPow(ll a, ll b)
{
    ll ans = 1, x = a % MOD;
    while (b)
    {
        if (b & 1)
            ans = mulMod(ans, x) % MOD;
        x = mulMod(x, x) % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, K, x, two = 2;
    while (cin >> N >> K, N, K)
    {

        ll ans = ((fastPow(N, N) % MOD + (two * fastPow(N - 1, N - 1) % MOD) % MOD) % MOD + (fastPow(N, K) % MOD + (two * fastPow(N - 1, K) % MOD) % MOD) % MOD) % MOD;
        cout << ans << endl;
    }

    return 0;
}
// END OF SOURCE CODE