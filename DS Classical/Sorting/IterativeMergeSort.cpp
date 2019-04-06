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

void merge(vector<ll> &V, ll low, ll mid, ll high)
{
    vector<ll> A, B;
    for (int i = low; i <= mid; i++)
        A.push_back(V[i]);

    for (int i = mid + 1; i <= high; i++)
        B.push_back(V[i]);

    ll i = 0, j = 0, k = low;
    while (i < A.size() and j < B.size())
    {
        if (A[i] <= B[j])
            V[k++] = A[i++];
        else
            V[k++] = B[j++];
    }

    while (i < A.size())
        V[k++] = A[i++];
    while (j < B.size())
        V[k++] = B[j++];
}

void mergeSort(vector<ll> &V, ll low, ll high)
{
    if (low < high) // low == high, one element is always sorted
    {
        ll mid = low + ((high - low) >> 1);
        mergeSort(V, low, mid);
        mergeSort(V, mid + 1, high);
        merge(V, low, mid, high);
    }
}

void iterativeMergeSort(vector<ll> &V) // merging two subarrays which are internally sorted
{
    for (int gap = 1; gap <= V.size() - 1; gap <<= 1) // size 1 is already sorted
    {
        for (int start = 0; start < V.size(); start += 2 * gap) // start is 0, mid is 1, end is 2
        {
            ll mid = start + gap - 1;
            ll end = min(start + 2 * gap - 1, (int)V.size() - 1);
            merge(V, start, mid, end);
        }
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
        iterativeMergeSort(V);

        for (int i = 0; i < V.size(); i++)
            cout << V[i] << " ";

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE