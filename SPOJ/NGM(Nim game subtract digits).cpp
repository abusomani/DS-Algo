//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Question is given a number N, you can subtract from N, any of its non-zero digits
    i.e. 139 => ( 138 | 136 | 130).
    Subtracted number becomes the new number.
    You have to tell who makes it zero.

    Pattern is, (1 to 9) 1st wins. for 10, 2 wins. And if we keep looking, any number divisible by 10 is losing side.
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
    ll N;
    cin >> N;
    if (N % 10 == 0)
        cout << 2;
    else
        cout << 1 << endl
             << N % 10 << endl;
    return 0;
}
// END OF SOURCE CODE