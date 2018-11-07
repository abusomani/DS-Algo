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

void prettyPrint(string s)
{
    for (int i = 0; i < 2; i++)
        cout << s[i];
    cout << " ";
    for (int i = 2; i < 10; i++)
        cout << s[i];
    cout << " ";
    for (int i = 10; i < 14; i++)
        cout << s[i];
    cout << " ";
    for (int i = 14; i < 18; i++)
        cout << s[i];
    cout << " ";
    for (int i = 18; i < 22; i++)
        cout << s[i];
    cout << " ";
    for (int i = 22; i < 26; i++)
        cout << s[i];
    cout << " ";
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
        ll N, K;
        cin >> N;
        multimap<string, ll> MM;
        MM.clear();
        for (int i = 0; i < N; i++)
        {
            string s = "", x;
            for (int j = 0; j < 6; j++)
                cin >> x, s += x;
            if (MM.find(s) != MM.end())
            {
                multimap<string, ll>::iterator it = MM.find(s);
                pair<string, ll> P = *it;
                MM.erase(it);
                MM.insert(make_pair(P.first, P.second + 1));
            }
            else
            {
                MM.insert(make_pair(s, 1));
            }
        }

        for (multimap<string, ll>::iterator it = MM.begin(); it != MM.end(); it++)
        {
            pair<string, ll> P = *it;
            prettyPrint(P.first);
            cout << P.second << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE