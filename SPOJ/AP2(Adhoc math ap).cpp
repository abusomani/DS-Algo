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

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll X, Y, Z, N, d, a;
        cin >> X >> Y >> Z;
        N = (Z << 1) / (X + Y);
        d = (Y - X) / (N - 5);
        a = X - 2 * d;
        cout << N << endl;
        for (int i = 1; i <= N; i++)
            cout << (a + (i - 1) * d) << " ";
        cout<<endl;
    }
    return 0;
}
// END OF SOURCE CODE