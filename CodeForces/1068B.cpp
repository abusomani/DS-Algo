//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    LCM(a,b)/a => b/gcd(a,b) => basically number of divisors
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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
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
        ll N, K, i = 1;
        cin >> N;
        ll ans = 0;
        for (i = 1; i < sqrt(N); i++)
        {
            if (N % i == 0)
                ans += 2;
        }
        cout << ans + (i * i == N);
    }
    return 0;
}
// END OF SOURCE CODE