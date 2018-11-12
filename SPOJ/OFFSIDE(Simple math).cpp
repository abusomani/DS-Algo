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
    ll N, M, x;
    while (cin >> N >> M, N, M)
    {
        ll minA = MOD, minB = MOD, minC = MOD;
        for (int i = 0; i < N; i++)
            cin >> x, minA = min(minA, x);

        for (int i = 0; i < M; i++)
        {
            cin >> x;
            if (x < minB)
                minC = minB, minB = x;
            else if (x >= minB and x <= minC)
                minC = x;
        }
        if (minA < minB or minA < minC)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}
// END OF SOURCE CODE