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
const ll INF = 1e18;
// 8 directions
const ll rows[] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll cols[] = {0, 0, 1, -1, 1, -1, -1, 1};

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        ll N, K, a = 0, d = 0;
        cin >> N;
        string s;
        cin >> s;
        for (int i = 0; i < N; i++)
            if (s[i] == 'A')
                a++;
            else
                d++;
        if (a > d)
            cout << "Anton";
        else if (a == d)
            cout << "Friendship";
        else
            cout << "Danik";
    }
    return 0;
}
// END OF SOURCE CODE