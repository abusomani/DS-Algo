//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Forming the next permutation ( for number with 10^6 digits)

    Traverse from back till its increasing
    let say we stop at i
    if i == 0, means reversely sorted
    else
    (i-1) is the number that has to be swapped with just greater number in range [i, V.end())

    find just greater number using pair<ll,ll>P as (HIGH_VALUE, i) in the above range
    swap it with V[i-1]

    and sort(V.begin()+i, V.end())

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

bool hasNextPermutation(vector<ll> &V)
{
    int i = V.size() - 1;                 // start from end
    while (i >= 1 and (V[i] <= V[i - 1])) // keep on traversing towards start till it is an increasing sequence
        i--;

    if (i == 0)
        return false; // reversely sorted

    // now from i to N - 1, find the digit just greater than (i-1) and swap it

    pair<ll, ll> P = make_pair(MOD, i); // to store index of just greater number
    for (int k = i; k < V.size(); k++)
    {
        if (V[k] < P.first and V[k] > V[i - 1])
            P.first = V[k], P.second = k;
    }

    swap(V[i - 1], V[P.second]);

    // sort the part from i to end

    sort(V.begin() + i, V.end());

    return true;
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
        ll N, K, x;
        cin >> N;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);
        if (hasNextPermutation(V))
        {
            for (int i = 0; i < N; i++)
                cout << V[i];
        }
        else
            cout << -1;

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE