//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    (axb) + c = d x (e+f) // Both sides can be computed in O(n^3)
    Now as numbers as distinct, for each occurence of LHS, find all occurence in RHS. summation of these is answer.

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
    ll N, K, x;
    cin >> N;
    ll arr[N];
    vector<ll> LHS, RHS;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // all possible (a x b) + c == LHS
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                LHS.push_back((arr[i] * arr[j]) + arr[k]);

    // all possible d x (e + f) == RHS ( d != 0)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (arr[k] != 0)
                    RHS.push_back((arr[i] + arr[j]) * arr[k]);

    sort(LHS.begin(), LHS.end());
    sort(RHS.begin(), RHS.end());

    ll ans = 0;
    for (int i = 0; i < LHS.size(); i++)
    {
        ll low = lower_bound(RHS.begin(), RHS.end(), LHS[i]) - RHS.begin();
        ll high = upper_bound(RHS.begin(), RHS.end(), LHS[i]) - RHS.begin();
        ans += (high - low);
    }

    cout << ans << endl;

    return 0;
}
// END OF SOURCE CODE