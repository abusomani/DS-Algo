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

ll partition(vector<ll> &V, ll low, ll high)
{
    ll pivot_key = V[high]; // assuming pivot is at high

    ll start = low - 1;
    for (int i = low; i <= high; i++)
    {
        if (V[i] < pivot_key)
        {
            swap(V[++start], V[i]); // so small elements go to left
        }
    }
    swap(V[++start], V[high]);
    return start;
}

void quickSort(vector<ll> &V, ll low, ll high)
{
    if (low < high)
    {
        ll pivot = partition(V, low, high);
        quickSort(V, low, pivot - 1); // because pivot is at right place
        quickSort(V, pivot + 1, high);
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

        // mergeSort(V, 0, V.size() - 1);
        quickSort(V, 0, V.size() - 1);

        for (int i = 0; i < V.size(); i++)
            cout << V[i] << " ";

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE