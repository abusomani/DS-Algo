//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Minimum insertion to make a string palindrome

    Recursive logic :
    let l = 0, r = N-1
    if l == r return 0 // no insertion required
    if str[l] == str[r] so already they are helping in making a palindrome so call
        f(l+1, r-1)
    else
        we can either insert a character on left of l or on right of r , so 1 insertion is surely required
        so 1 + min( f(l,r-1) , f(l+1,r))


    Iterative dp [][]

    as its a bottom up dp,
    i represents string of length i
    and j represents from 0 to N

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 6115;
ll dp[MAX_SIZE][MAX_SIZE];

string str;
ll minInsertToPalin(ll l, ll r) // RECURSIVE SOLUTION
{
    if (l >= str.size() or r < 0)
        return 0;
    if (l == r) // if only one character that means it is a palindrome so nothing to insert
        return 0;
    if (str[l] == str[r])
        return minInsertToPalin(l + 1, r - 1);
    else
        return (1 + min(minInsertToPalin(l, r - 1), minInsertToPalin(l + 1, r)));
}

ll minInsertDP()
{
    for (int i = 0; i <= str.size(); i++)
        dp[i][i] = 0; // single character is a palindrome

    for (int len = 2; len <= str.size(); len++) // from string of length 2 to string length
    {
        for (int start = 0; start < str.size() - len + 1; start++) //start means start of string, all substrings of length LEN
        {
            int end = start + len - 1; // end of string

            if (str[start] == str[end] and len == 2) // if both characters equal and length 2, so 0 operations
                dp[start][end] = 0;

            else if (str[start] == str[end]) //else if length is greater than 2 operations are equal to inside subproblem
                dp[start][end] = dp[start + 1][end - 1];

            else //else if char are not equal either we can insert at last or start so it will minimum of these two operations
                dp[start][end] = 1 + min(dp[start + 1][end], dp[start][end - 1]);
        }
    }

    return dp[0][str.size() - 1];
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
        memset(dp, INT_MAX, sizeof(dp));
        cin >> str;
        cout << minInsertDP() << endl;
    }
    return 0;
}
// END OF SOURCE CODE