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

void insertionSort(vector<ll> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        ll key = arr[i];
        ll j = i - 1;
        while (j >= 0 and arr[j] > key)
            arr[j + 1] = arr[j], j--;

        arr[j + 1] = key;
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

        for (int i = 0; i < V.size(); i++)
            cout << V[i] << " ";

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE