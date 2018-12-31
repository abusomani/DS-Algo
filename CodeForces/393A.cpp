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
        string str;
        cin >> str;
        ll e = 0, i = 0, n = 0, t = 0;
        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            if (ch == 'e')
                e++;
            if (ch == 'i')
                i++;
            if (ch == 'n')
                n++;
            if (ch == 't')
                t++;
        }
        cout << min((n - 1) / 2, min(e / 3, min(i, t)));
    }
    return 0;
}
// END OF SOURCE CODE