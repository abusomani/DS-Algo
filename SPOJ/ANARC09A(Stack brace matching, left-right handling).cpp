//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
{{}},  {}{}  => stable

So, whenever { comes, push it on stack. 
Whenver } comes, see the top, if it matches, pop and dont increment count because, it is stable. Else, increase count by 1 and push {
At end, add stack's size / 2 
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
    ll T = 0;
    while (true)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
            break;
        T++;
        ll ans = 0, left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '{')
                left++;
            else if (s[i] == '}')
            {
                if (left)
                    left--;
                else
                    ans++, left++;
            }
        }
        ans += left / 2;
        cout << T << ". " << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE