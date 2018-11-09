//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Number of valid hexagonal packing is 
    1 , 7 , 19
    i.e. 1 + 6*(t-1)

    To check if a number is valid
    N = 1 + summation of AP with starting term 6 and common difference of 6
    (N -  1) = X[12 + (X-1)6]/2
    => (N-1) = 3X(X+1)
    For a valid solution to exist. Discriminant should be a perfect square ( b^2 - 4ac)
    So, 1 + 4(N-1)/3 must be a perfect square
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
    while (true)
    {
        cin >> N;
        if (N == -1)
            break;
        ll val = 1 + (4 * (N - 1)) / 3;
        ll sqt = (int)sqrt(val);
        if (sqt * sqt == val)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
// END OF SOURCE CODE