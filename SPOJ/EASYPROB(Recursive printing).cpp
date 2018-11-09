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

void powerOfTwoPrint(ll N)
{
    ll n = N;
    if (N <= 3)
    {
        if (N == 3)
            cout << "2+2(0)";
        else if (N == 2)
            cout << "2";
        else if (N == 1)
            cout << "2(0)";
        else
            cout << "ERROR";
        return;
    }
    int cnt = 0;
    while (n > 0)
        cnt++, n /= 2;

    ll diff = N - pow(2, cnt - 1); // number just smaller than N

    cout << "2(";
    powerOfTwoPrint(cnt - 1);
    cout << ")";
    if (diff != 0)
    {
        cout << "+";
        powerOfTwoPrint(diff);
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        cout << N << "=";
        powerOfTwoPrint(N);
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE