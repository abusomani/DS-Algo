//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    On a close look :
    BC^2 = AB^2 + AC^2 ( S = AB^2 + AC)
    So, 4r^2 = S - AC + AC^2, to get maximum for S, we differentiate. So we get AC = 0.5 always.
    Max value of S = 4r^2 + 0.25
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
        cout << "Case " << cnt << ": " << (4 * N * N) << ".25" << endl;
    }
    return 0;
}
// END OF SOURCE CODE