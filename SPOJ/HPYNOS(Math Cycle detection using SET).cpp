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

ll smOfSquareOfDigits(ll N)
{
    ll ans = 0;
    while (N)
    {
        ll x = N % 10;
        ans += x * x;
        N /= 10;
    }

    return ans;
}

ll isHappy(ll N)
{
    set<ll> S;
    ll cnt = 0, val = N;
    S.insert(N);
    while (true)
    {
        val = smOfSquareOfDigits(val);
        if (S.find(val) != S.end()) // already present
            return -1;
        else
            S.insert(val);
        cnt++;
        if (val == 1)
            return cnt;
    }
    return 0;
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N;
    cin >> N;
    ll steps = isHappy(N);
    cout << steps;

    return 0;
}
// END OF SOURCE CODE