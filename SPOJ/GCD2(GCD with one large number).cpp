//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    GCD logic is simple,
    if either number is 0, return the other number,
    else a, b%a

    so if we see, we can directly provide (b%a) when b is very large : 1000 digits and 'a' is a long long
    take b as string
    start forming b while taking %a at each step i.e.
    let num = b[0] - '0'
    for (int i = 1; i < b.size(); i++)
                num = (num * 10 + (b[i] - '0')) % a;
    THIS IS BASED ON THE HAND DIVISION WHICH WE DID FOR FINDING THE REMAINDER
    however large be the number, divide it from right(MSB) one by one till the remainder is smaller than A
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll a;
        cin >> a;
        string s;
        cin >> s;
        if (a == 0)
            cout << s << endl;
        else
        {
            ll ans = s[0] - '0';
            for (int i = 1; i < s.size(); i++)
                ans = (ans * 10 + (s[i] - '0')) % a;
            cout << gcd(a, ans) << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE