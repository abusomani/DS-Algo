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
        ll N, K = 0, sm = 0;
        cin >> N;
        if (N == -1)
            break;

        ll arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i], sm += arr[i];

        if (sm % N == 0)
        {
            ll mean = sm / N;
            for (int i = 0; i < N; i++)
                if (arr[i] < mean)
                    K += (mean - arr[i]);
            cout<<K<<endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE