//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/* CORE LOGIC : if 0 is not the present character then the number of words formed till i must be same as (i-1)
so if present char is not 0 then dp[i] = dp[i-1]
let say if the value of 2 char is > 9 and  <= 26, then all words till (i-2) can also club up
so, dp[i-2] would be added for above with boundary case as i == 1, where only 1 would be added
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
    while (true)
    {
        string s;
        cin >> s;
        if (s.size() == 1 and s[0] == '0')
            break;
        else if (s.size() == 1)
            cout << 1 << endl;
        else
        {
            ll dp[s.size() + 1];
            memset(dp, 0, sizeof(dp));
            dp[0] = 1; // first character always one
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] - '0') // if zero then dp[i-2] will be added as (i-1,0) become intact group
                {
                    dp[i] = dp[i - 1];
                }

                ll val = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if (val <= 26 and val > 9)
                {
                    dp[i] += ((i == 1) ? 1 : dp[i - 2]);
                }
            }
            cout << dp[s.size() - 1] << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE