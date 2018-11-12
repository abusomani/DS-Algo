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
    cin >> T;
    while (T--)
    {
        char op;
        ll res, a;
        cin >> res;
        while (true)
        {
            cin >> op;
            if (op == '=')
                break;

            cin >> a;

            switch (op)
            {
            case '+':
                res += a;
                break;
            case '-':
                res -= a;
                break;
            case '*':
                res *= a;
                break;
            case '/':
                res /= a;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
// END OF SOURCE CODE