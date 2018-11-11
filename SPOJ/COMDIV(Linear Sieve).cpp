//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Using sieve stored all primes,
    iterated over all numbers and storing the prime factors will TLE

    If we observe :
    Number of common divisors is 2^p*3^q...N^X => (p+1)*(q+1)*(X+1)
    Because for each prime, we have its power+1 possibility to select 1, p, p^2, p^3 ... p^n primes

    So basically we need the GCD's factors

    Sieve of eratosthenes gives TLE as it is (Nxlog(logN))
    So we use linear sieve :
    SPF[N+1] // 0 initially means all prime
    if(SPF[i] == 0) SPF[i] = i, primes.add(i)

    for(j=0; j<primes.size() and i*primes[j] < N and primes[j] <= spf[i] ; j++) SPF[i*primes[j]] = primes[j]
*/
#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%ld", &x)

typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_SIZE = 1000005;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

vector<ll> Primes;
ll SPF[MAX_SIZE]; // Smallest prime factor

void sieveLinear()
{
    for (int i = 2; i < MAX_SIZE; i++)
    {
        if (SPF[i] == 0) // Prime number
        {
            SPF[i] = i;
            Primes.push_back(i);
        }

        for (int j = 0; j < Primes.size() and i * Primes[j] < MAX_SIZE and Primes[j] <= SPF[i]; j++) // runs once for each composite number
            SPF[i * Primes[j]] = Primes[j];
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    // computeDivisors();  => Will give TLE
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    // sieveLinear();
    ll T;
    sc(T);
    while (T--)
    {
        ll N, M, K, x;
        sc(N);
        sc(M);

        if (gcd(N, M) == 1)
            printf("1\n");
        else
        {
            ll ans = 0;
            ll Num = gcd(N, M);
            for (int i = 1; i <= sqrt(Num); i++)
            {
                if (Num % i == 0)
                {
                    ans++;
                    if (i * i != Num)
                        ans++;
                }
            }

            printf("%ld\n", ans);
        }
    }
    return 0;
}
// END OF SOURCE CODE