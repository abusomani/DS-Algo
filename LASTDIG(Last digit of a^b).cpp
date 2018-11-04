//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// (a^b) = a^(binary representation of b) = keep a variable and square it each time, multiply it to answer only if set bit of b is found
ll fastPower(ll a, ll b)
{
    ll ans = 1, x = a;
    while (b)
    {
        if (b & 1) ans = (ans * x) % 10;
        x = (x * x) % 10;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll a, b;
        cin >> a >> b;
        cout << fastPower(a, b) << endl;
    }
    return 0;
}
// END OF SOURCE CODE