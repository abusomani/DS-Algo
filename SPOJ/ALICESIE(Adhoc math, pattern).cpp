//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    brute force to see pattern
    For every number basically, we are marking half of the numbers because from N to N/2 there wont be any proper divisor
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

bool sieveOfAlice[1005];

ll sieveModified(ll N)
{
    for (int i = N; i >= 2; i--)
    {
        if (!sieveOfAlice[i])
        {
            ll num = i;
            for (int k = 1; k <= sqrt(num); k++)
            {
                if (num % k == 0)
                {
                    sieveOfAlice[k] = true;
                    ll j = num / k;
                    if (j != num)
                        sieveOfAlice[j] = true;
                }
            }
        }
    }
    ll cnt = 0;
    for (int i = 2; i <= N; i++)
        if (!sieveOfAlice[i])
            cnt++;
    return cnt;
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
        ll N, K, x;
        cin >> N;
        if (N == 2)
            cout << 1 << endl;
        else
            cout << ((N + 1) >> 1) << endl;
    }
    return 0;
}
// END OF SOURCE CODE