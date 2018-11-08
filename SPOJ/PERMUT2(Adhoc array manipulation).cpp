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
        vector<ll> A, B;
        map<ll, ll> Mp;
        A.push_back(0);
        B.push_back(0);
        for (int i = 1; i <= N; i++)
            B.push_back(0);
        for (int i = 1; i <= N; i++)
            cin >> x, A.push_back(x), B[x] = i;
        bool isAmb = true;
        for (int i = 1; i <= N; i++)
            if (A[i] != B[i])
                isAmb = false;
        if (isAmb)
            cout << "ambiguous" << endl;
        else
            cout << "not ambiguous" << endl;
    }
    return 0;
}
// END OF SOURCE CODE