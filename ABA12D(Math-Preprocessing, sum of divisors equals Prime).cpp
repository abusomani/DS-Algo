//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Sum of divisors for X = p1^a * p2 ^b * ... * pn^n = ((p1^(a+1) - 1)/(p1-1) * (p2^(b+1) - 1)/(p2 - 1).... * (pn^(n+1) - 1)/(pn - 1))
    For prime, sum of divisors is (p + 1)
    The logic to this problem is : 

    Whatever be the number, whose divisors sum to a prime are always perfect squares. So in a given range, find the perfect squares and the sum of divisors
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll PRIME_RANGE = 1000005;
bool isPrime[PRIME_RANGE];
set<ll> Primes;
set<ll> NumberWithSumOfDivisorsPrime;

void mark(ll N)
{
    for (ll i = N * N; i < PRIME_RANGE; i += N)
        isPrime[i] = false;
}

void sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    mark(2);
    Primes.insert(2);
    for (ll i = 3; i <= sqrt(PRIME_RANGE); i += 2)
        if (isPrime[i])
            mark(i), Primes.insert(i);

    for (ll i = 1001; i < PRIME_RANGE; i += 2)
        if (isPrime[i])
            Primes.insert(i);
}

// Prime factorization sum of divisors
ll sumOfDivisors(ll N)
{
    if (N == 1)
        return 1;

    if (isPrime[N])
        return (N + 1);

    ll smOfDiv = 1, lim = sqrt(N);

    for (set<ll>::iterator it = Primes.begin(); it != Primes.end(); it++)
    {
        ll val = *it;
        if (val > lim)
            break;
        ll cnt = 1;
        while (N % val == 0)
            cnt *= val, N /= val;

        smOfDiv *= ((cnt > 1) ? (cnt * val - 1) / (val - 1) : 1);
    }
    if (N > 2)
        smOfDiv *= (N * N - 1) / (N - 1);

    return smOfDiv;
}

// Elementary sum of divisors.
ll smofdiv(ll N)
{
    ll ans = 0;
    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            ans += i;
            if (i * i != N)
                ans += N / i;
        }
    }
    return ans;
}

// Elementary Primality Testing
bool isPrimeNumber(ll N)
{
    if (N < PRIME_RANGE)
        return isPrime[N];
    ll lim = sqrt(N);
    for (set<ll>::iterator it = Primes.begin(); it != Primes.end(); it++)
    {
        ll val = *it;
        if (val > lim)
            break;
        if (N % val == 0)
            return false;
    }
    return true;
}

void preprocess()
{
    NumberWithSumOfDivisorsPrime.insert(2);
    for (int i = 4; i <= PRIME_RANGE; i++)
    {
        ll x = (ll)sqrt(i);
        if (x * x == i)
            if (isPrimeNumber(smofdiv(i)))
                NumberWithSumOfDivisorsPrime.insert(i);
    }
}

int main()
{
    fastio;
    sieve();
    preprocess();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll A, B, K, cnt = 0;
        cin >> A >> B;
        for (set<ll>::iterator it = NumberWithSumOfDivisorsPrime.begin(); it != NumberWithSumOfDivisorsPrime.end(); it++)
        {
            ll val = *it;
            if (val >= A and val <= B)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
// END OF SOURCE CODE