//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    to find modular inverse there are two ways in LogM complexity
    1. If M is prime, use fermat's theorem i.e a^(m-1) = 1 (mod m), so a^(-1) = a^(m-2), so simply find fastPower(a,m-2)
    2. If M is not prime, but a and M are coprime, use extended euclid ( ax + My = 1(modM))
        ExtendedEuclid(a,b,&x,&y)
        {
            if a == 0 { x = 0, y = 1, return b}
            x1,y1
            gcd = ExtendedEuclid(b%a,b,x1,y1)
            x = y1 - (b/a)*x1
            y = x1

            return gcd
        }
    3. If M is not prime and a and M are not coprime, inverse wont exist

    THIS ALL WAS DONE because simple formula for Nth level is (3N^2 + N)/2
    else
    can be solved using dp
    dp[i] = (3*N-1) + d[i-1]
    
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll LARGE_MOD = 1000000007;
const ll SMALL_MOD = 1000007;

ll mulMod(ll a, ll b, ll MOD)
{
    ll ans = 0, x = a;
    while (b)
    {
        if (b & 1)
            ans = (ans + x) % MOD;

        x = (x + x) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

ll fastPow(ll a, ll b, ll MOD)
{
    ll ans = 1, x = a;
    while (b)
    {
        if (b & 1)
            ans = mulMod(ans, x, MOD) % MOD;
        x = mulMod(x, x, MOD) % MOD;
        b >>= 1;
    }
    return ans;
}

// BASED ON FERMAT's LITTLE THEOREM
// if m is prime, a^(M-1) = 1(mod M). so, a^(-1) = a^(M-2)
ll inverseModFermat(ll a, ll m, ll MOD)
{
    return fastPow(a, m - 2, MOD) % MOD;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// finding ax + by = 1(modM)
ll extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = extendedEuclid(b % a, a, x1, y1);

    //update x and y using result of recursive call

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

// if m is not prime, and A and M are coprime we use extended euclid to find the inverse
ll inverseModularCoPrime(ll a, ll MOD)
{
    ll x, y;
    ll g = extendedEuclid(a, MOD, x, y);
    if (g == 1)                       // co prime
        return (x % MOD + MOD) % MOD; // Handling negative x
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;

        ll inverseTwo = inverseModularCoPrime(2, SMALL_MOD);
        ll ans = mulMod((mulMod(3, mulMod(N, N, SMALL_MOD) % SMALL_MOD, SMALL_MOD) % SMALL_MOD + N % SMALL_MOD) % SMALL_MOD, inverseTwo, SMALL_MOD) % SMALL_MOD;
        cout << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE