//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N;
    while(cin>> N and N != 0)
    {
        // Number of square in NxN is (1^2 + 2 ^2 + ....... + N^2) = n*(n+1)*(2*n + 1)/6
        ll ans = N *(N+1) *(2*N + 1) / 6;
        cout<<ans<<endl;
    }
    return 0;
}
// END OF SOURCE CODE