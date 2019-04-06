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

void bubbleSort(vector<ll> &V)
{
    for (int i = 0; i < V.size() - 1; i++)
    {
        for (int j = 0; j < V.size() - i - 1; j++) // after ith iteration (N - i)th value is correctly placed
        {
            if (V[j] > V[j + 1])
                swap(V[j], V[j + 1]); // can be optimized to break from inner loops if no swap happened
        }
    }
}

void bubbleSortRecur(vector<ll> &V, int pass)
{
    if (pass == V.size() - 1)
        return;

    for (int i = 0; i < V.size() - pass - 1; i++)
    {
        if (V[i] > V[i + 1])
            swap(V[i], V[i + 1]);
    }
    bubbleSortRecur(V, pass + 1);
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

        bubbleSortRecur(V, 0);

        for (int i = 0; i < V.size(); i++)
            cout << V[i] << " ";

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE