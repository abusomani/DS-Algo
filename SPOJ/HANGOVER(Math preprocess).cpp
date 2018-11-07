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
const ll MAX = 1005;
vector<double> cards;

double roundToTwo(double x)
{
    double value = (ll)(x * 100 + 0.5);
    return (double)value / 100;
}

void preprocess()
{
    cards.push_back(0);
    cards.push_back(0);
    for (int i = 2; i < MAX; i++)
        cards.push_back(cards[i - 1] + (double)1 / i);
}
int main()
{
    fastio;
    preprocess();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    double N;
    while (cin >> N , N)
    {
        ll val = lower_bound(cards.begin(), cards.end(), N) - cards.begin(); // not lower than N
        cout << val - 1 << " card(s)" << endl;
    }
    return 0;
}
// END OF SOURCE CODE