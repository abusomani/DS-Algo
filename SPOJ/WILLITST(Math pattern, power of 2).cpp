//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Simple proof is, number reduces to 1 if power of 2
    and no power of 2 is of the form 3*n + 3 because , power of 2 - 3 will be either 1 mod 3 or 2 mod 3
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
    ll N;
    cin >> N;
    if (N <= 2)
        cout << "TAK";
    else if (!(N & (N - 1)))
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}
// END OF SOURCE CODE