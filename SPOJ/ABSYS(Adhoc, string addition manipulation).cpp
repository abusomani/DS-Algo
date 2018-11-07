//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    string.find()  return string::npos if not found
    stoll and stoi convert string to ll and int
*/
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
    ll T;
    cin >> T;
    while (T--)
    {
        string s[10];
        for (int i = 0; i < 5; i++)
            cin >> s[i];
        ll a = 0, b = 0;

        // FIND returns string::npos if value not found
        if (s[0].find('m') != string::npos)
        {
            cout << (stoll(s[4]) - stoll(s[2])) << " + " << s[2] << " = " << s[4] << endl;
        }
        else if (s[2].find('m') != string::npos)
        {
            cout << s[0] << " + " << (stoll(s[4]) - stoll(s[0])) << " = " << s[4] << endl;
        }
        else if (s[4].find('m') != string::npos)
        {
            cout << s[0] << " + " << s[2] << " = " << (stoll(s[0]) + stoll(s[2])) << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE