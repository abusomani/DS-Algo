//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Counting equilateral triangles of size N:
    READING : http://mathforum.org/library/drmath/view/56194.html
    N odd = (N*(N+2)*(2n+1) - 1)/8
    else N*(N+2)*(2N+1) /8

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

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
        ll ans = N * (N + 2) * (2 * N + 1);
        if (N % 2)
            cout << ((ans - 1) >> 3) << endl;
        else
            cout << (ans >> 3) << endl;
    }
    return 0;
}
// END OF SOURCE CODE