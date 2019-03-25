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

const ll MAX_SIZE = 20;

void updateFreq(vector<ll> &fenwickTree, int index, ll value)
{
    if (index >= fenwickTree.size())
        return;

    fenwickTree[index] += value;
    index += index & -index;
    updateFreq(fenwickTree, index, value);
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
        ll N, Q, x;
        cin >> N >> Q;

        vector<ll> fenwickTree(MAX_SIZE);
        ll collection[N + 1];

        for (int i = 1; i <= N; i++)
        {
            updateFreq(fenwickTree, i, 1);
            collection[i] = N - i + 1;
        }

        int count = N;
        while (Q--)
        {
            count++;
            cin >> x;
            ll ans = 0, idx = collection[x];

            while (idx > 0)
            {
                ans += fenwickTree[idx];
                idx -= idx & -idx;
            }

            updateFreq(fenwickTree, collection[x], -1);
            collection[x] = count;
            updateFreq(fenwickTree, collection[x], 1);

            cout << N - ans << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE