//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Givan arr, find all pairs of (i,j) such that i != j and ai-aj = X
    sort and iterate
    lower_bound and upper_bound for a[i] + X
    difference in these positions mean those many numbers satisfy
    TRICKY : if i != j is required, see if it exists in this [low,high), if it does, subtract 1
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
        ll N, K, ans = 0, x;
        cin >> N >> K;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);

        sort(V.begin(), V.end());

        for (int i = 0; i < N; i++)
        {
            ll low = lower_bound(V.begin(), V.end(), K + V[i]) - V.begin();
            ll high = upper_bound(V.begin(), V.end(), K + V[i]) - V.begin();
            ans += (high - low);

            // TRICKY step, if i != j is required, see if it exists in this [low,high), if it does, subtract 1
            if (i <= high and i >= low)
                ans--;
        }

        cout << "Case " << cnt << ": " << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE