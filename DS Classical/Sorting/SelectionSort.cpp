//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Select the minimum element and put it at beginning
*/
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

void insertionSort(vector<ll> &V)
{
    for (int i = 0; i < V.size() - 1; i++)
    {
        ll min_idx = i;
        for (int j = i + 1; j < V.size(); j++)
            min_idx = (V[j] < V[min_idx]) ? j : min_idx;

        swap(V[min_idx], V[i]); // not stable, can be made stable if you shift all values from i to min one place right and then a[i] = key
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);

        insertionSort(V);

        for (int i = 0; i < N; i++)
            cout << V[i] << " ";
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE