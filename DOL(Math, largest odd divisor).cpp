//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    If number is odd, it is the largest odd divisor
    else if number is even
        then keep on dividing by 2 until its odd.

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
    ll T, cnt = 0;
    cin >> T;
    while (T--)
    {
        cnt++;
        ll N, K, x;
        cin >> N;
        if (N & 1)
            cout << "Case " << cnt << ": " << N << endl;
        else
        {
            while (!(N & 1))
                N >>= 1;
            cout << "Case " << cnt << ": " << N << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE