//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    while (true)
    {
        ll N, K, x;
        cin >> N;
        if (N == 0)
            break;
        string inp;
        cin >> inp;
        bool toggle = false;
        for (int i = 0; i < inp.size(); i++)
        {
            if (i % N == 0 and i)
            {
                toggle = !toggle;
                if (toggle)
                    reverse(inp.begin() + i, inp.begin() + i + N); 
                    // reverse [first, last)  , so if (i, i + N) is given, total of N characters from ith index would be reversed
            }
        }
        string out = "";
        for (int i = 0; i < N; i++)
        {
            ll j = i;
            while (j < inp.size())
            {
                out += inp[j];
                j += N;
            }
        }
        cout << out << endl;
    }
    return 0;
}
// END OF SOURCE CODE