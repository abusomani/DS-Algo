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

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, x;
    while (cin >> N, N)
    {
        bool isPossible = true;
        stack<ll> S;
        vector<ll> V;
        V.clear();

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            if (S.empty())
                S.push(x);

            else
            {
                if (S.top() > x)
                    S.push(x);
                else
                {
                    while (!S.empty() and x > S.top())
                        V.push_back(S.top()), S.pop();
                    S.push(x);
                }
            }
        }
        while (!S.empty())
            V.push_back(S.top()), S.pop();
        for (int i = 0; i < V.size() - 1; i++)
            if (V[i] > V[i + 1])
                isPossible = false;

        if (isPossible)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
// END OF SOURCE CODE