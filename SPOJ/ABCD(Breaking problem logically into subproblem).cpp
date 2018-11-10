//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Beautiful question :
    As there are 2 rows of 2N characters each, and total of 4 unique characters. We can break the question into
    N blocks of 2x2 each. and check in it

    Edge cases :
    2
    BDAB => Ans wont be ACCD but ACDC
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
map<char, ll> Mp;

int main()
{
    fastio;
    ll T;
    T = 1;
    while (T--)
    {
        Mp.clear();
        ll N;
        cin >> N;

        char last = 'Z';  // for the second character of last pair assigned
        char s[2][2 * N]; // input format

        set<char> St;
        set<char>::iterator it;
        for (int i = 0; i < (2 * N); i += 2)
        {
            for (int j = 0; j < 4; j++) // add A,B,C,D
                St.insert(('A' + j));

            cin >> s[0][i] >> s[0][i + 1];

            St.erase(s[0][i]);
            St.erase(s[0][i + 1]);

            it = St.begin();
            s[1][i] = *it;
            it++;
            s[1][i + 1] = *it;

            if (s[1][i] == last)
                swap(s[1][i], s[1][i + 1]);
            last = s[1][i + 1];
        }

        for (int i = 0; i < (2 * N); i++)
            cout << s[1][i];
    }
    return 0;
}
// END OF SOURCE CODE