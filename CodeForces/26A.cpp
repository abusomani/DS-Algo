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
const ll PRIME_RANGE = 10007;
vector<ll> Primes;
ll LP[PRIME_RANGE + 1];
void sieve()
{
    for (int i = 2; i <= PRIME_RANGE; i++)
    {
        if (LP[i] == 0)
        {
            Primes.push_back(i);
            LP[i] = i;
        }
        for (int j = 0; j < (int)Primes.size() and Primes[j] <= LP[i] and i * Primes[j] <= PRIME_RANGE; j++)
            LP[i * Primes[j]] = Primes[j];
    }
}
set<ll> AlmostPrimes;

void preprocess()
{
    for (int i = 2; i <= 3005; i++)
    {
        ll j = i, k = 0;
        set<ll> numP;
        for (int l = 0; l < Primes.size() and Primes[l] <= j; l++)
        {
            if (j % Primes[l] == 0)
            {
                numP.insert(Primes[l]);
                while (j % Primes[l] == 0)
                    j /= Primes[l];
            }
        }
        if (numP.size() == 2)
            AlmostPrimes.insert(i);
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    sieve();
    preprocess();
    ll T;
    T = 1;
    while (T--)
    {
        ll N, K, x, ans = 0;
        cin >> N;

        for (int i = 1; i <= N; i++)
        {
            if (AlmostPrimes.find(i) != AlmostPrimes.end())
                ans++;
        }
        cout << ans;
    }
    return 0;
}
// END OF SOURCE CODE