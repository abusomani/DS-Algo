//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    N boys divide M into (N+1) buckets. Each will have M/(N+1) and depending on modulus, one or more extra.
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
    while (true)
    {
        ll G, B;
        cin >> G >> B;
        if (G == B and G == -1)
            break;
        ll buckets = min(B, G) + 1;
        ll ans = (max(B, G) / buckets);
        if (max(B, G) % buckets == 0)
            cout << ans << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}
// END OF SOURCE CODE