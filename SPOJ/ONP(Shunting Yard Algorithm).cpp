//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
// Based on SHUNTING YARD ALGORITHM
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
    cin >> T;
    while (T--)
    {
        string inp;
        cin >> inp;

        queue<char> Q;
        stack<char> S;

        for (int i = 0; i < inp.size(); i++)
        {
            if (inp[i] >= 'a' and inp[i] <= 'z')
                Q.push(inp[i]);
            else
            {
                if (inp[i] == ')')
                {
                    while (!S.empty())
                    {
                        char tp = S.top();
                        S.pop();
                        if (tp == '(')
                            break;
                        Q.push(tp);
                    }
                }
                else
                    S.push(inp[i]);
            }
        }
        while (!Q.empty())
        {
            cout << Q.front();
            Q.pop();
        }
        cout<<endl;
    }
    return 0;
}
// END OF SOURCE CODE