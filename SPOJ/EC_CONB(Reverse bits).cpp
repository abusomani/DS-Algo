//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    reverse bits :
    push all %2 into vector
    then start from end and to answer = 0
    add pow(2, N-i-1)
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
    ll N, x;
    cin >> N;
    while (N--)
    {
        cin >> x;
        if (x & 1)
            cout << x << endl;
        else
        {
            ll ans = 0;
            vector<ll> V;
            while (x)
            {
                V.push_back(x % 2);
                x >>= 1;
            }
            for (int i = V.size() - 1; i >= 0; i--)
                if (V[i] == 1)
                    ans += (int)pow(2, V.size() - i - 1);
            cout << ans << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE