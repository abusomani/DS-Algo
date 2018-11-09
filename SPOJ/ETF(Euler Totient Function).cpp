//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Euler totient function 
    For N = N * (1 - 1/p1)(1 - 1/p2)....(1 - 1/pN) ... where p1,p2,... pN are prime factors of N

    easy way is to N -= N/P
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 1000005;

vector<ll> Primes;
bool isPrime[MAX_SIZE];

void mark(ll N)
{
    for (int i = N * N; i < MAX_SIZE; i += N)
        isPrime[i] = false;
}

void sieve()
{
    for (int i = 0; i < MAX_SIZE; i++)
        isPrime[i] = true;
    mark(2);
    Primes.push_back(2);
    for (int i = 3; i <= sqrt(MAX_SIZE); i++)
        if (isPrime[i])
            mark(i), Primes.push_back(i);
    for (int i = 1001; i < MAX_SIZE; i++)
        if (isPrime[i])
            Primes.push_back(i);
}

ll ETF(ll N)
{
    if (N <= 2)
        return 1;
    if (isPrime[N])
        return (N - 1);
    else
    {
        ll j = 0, lim = sqrt(N), ans = N;
        while (j < Primes.size())
        {
            if (Primes[j] > lim)
                break;

            if (N % Primes[j] == 0)
            {
                while (N % Primes[j] == 0) // reduce the number by repeated division
                    N /= Primes[j];

                ans -= ans / Primes[j];
            }
            j++;
        }

        if (N > 1) // last number greater than sqrt(N) was also a prime. FOR EXAMPLE N = 998, 499 is a prime
            ans -= ans / N;
        return ans;
    }
}

int main()
{
    fastio;
    sieve();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        cout << ETF(N) << endl;
    }
    return 0;
}
// END OF SOURCE CODE