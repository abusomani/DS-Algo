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
const ll MAX_SIZE = 100000000;
ll dp[MAX_SIZE] = {0};

void preprocess()
{
    for (ll i = 1; i < MAX_SIZE; i++)
    {
        dp[i] = max(dp[i / 2] + dp[i / 3] + dp[i / 4], i);
    }
}

ll numberOfCoins(ll N)
{
    if (N == 0)
        return 0;
    if (N < MAX_SIZE)
        return dp[N];
    else
        return max(N, numberOfCoins(N / 2) + numberOfCoins(N / 3) + numberOfCoins(N / 4));
}

int main()
{
    fastio;
    preprocess();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N;
    cin >> N;
    while (!cin.fail())
    {
        cout<<numberOfCoins(N)<<endl;
        cin>>N;
    }
    return 0;
}
// END OF SOURCE CODE
