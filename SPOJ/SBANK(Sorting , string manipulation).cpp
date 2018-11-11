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
    ll T;
    cin >> T;
    while (T--)
    {
        cin.ignore();

        ll N, K;
        cin >> N;
        string str;

        cin.ignore(); // to use getline, flush the newline

        map<string, ll> MM;
        MM.clear();
        for (int i = 0; i < N; i++)
        {
            getline(cin, str);
            MM[str]++;
        }
        for (map<string, ll>::iterator it = MM.begin(); it != MM.end(); it++)
        {
            pair<string, ll> P = *it;
            cout << P.first << " "; // if getline is used, cout will print with spaces
            cout << P.second << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE