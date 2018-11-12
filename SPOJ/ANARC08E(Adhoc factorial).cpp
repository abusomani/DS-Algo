//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Number of possibilities is simply rearranging x As and y Bs which is ANS = [(x+y)! / x! y!]
    so to check for what values of x and y (x+y) is equal to ANS
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
ll dp[21];

ll fact(ll N)
{
    if (N == 0 || N == 1)
        return 1;
    if (dp[N] != 0)
        return dp[N];
    return dp[N] = N * fact(N - 1);
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    fact(20);
    ll A, B;
    while (true)
    {
        cin >> A >> B;
        if (A == -1 and B == -1)
            break;

        ll possibilities = (fact((A + B)) / (fact(A) * fact(B)));
        if (possibilities == (A + B))
            cout << A << "+" << B << "=" << (A + B) << endl;
        else
            cout << A << "+" << B << "!=" << (A + B) << endl;
    }

    return 0;
}
// END OF SOURCE CODE