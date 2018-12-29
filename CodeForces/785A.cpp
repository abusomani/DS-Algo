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
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        map<string, ll> Mp;
        Mp["Tetrahedron"] = 4;
        Mp["Cube"] = 6;
        Mp["Octahedron"] = 8;
        Mp["Dodecahedron"] = 12;
        Mp["Icosahedron"] = 20;

        ll N, K, ans = 0;
        cin >> N;
        string s;
        for (int i = 0; i < N; i++)
            cin >> s, ans += Mp[s];
        cout << ans;
    }
    return 0;
}
// END OF SOURCE CODE