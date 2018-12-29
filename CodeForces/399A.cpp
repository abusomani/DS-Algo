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
        ll N, P, K, x;
        cin >> N >> P >> K;
        set<ll> St;
        for (int i = (P - K); i <= (P + K); i++)
        {
            if (i <= 0 or i > N)
                continue;
            else
                St.insert(i);
        }
        if (St.find(1) == St.end())
            cout << "<< ";
        for (set<ll>::iterator it = St.begin(); it != St.end(); it++)
        {
            ll val = *it;
            if (val == P)
                cout << "(" << val << ")"
                     << " ";
            else
                cout << val << " ";
        }
        if (St.find(N) == St.end())
            cout << ">>";
    }
    return 0;
}
// END OF SOURCE CODE