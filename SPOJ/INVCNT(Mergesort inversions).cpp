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
const ll MAX_SIZE = 200005;
ll arr[MAX_SIZE];

ll merge(ll low, ll mid, ll high)
{
    vector<ll> A, B;
    for (int i = low; i <= mid; i++)
        A.push_back(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        B.push_back(arr[i]);

    ll inv_count = 0, i = 0, j = 0, k = low;

    while (i < A.size() and j < B.size())
    {
        if (A[i] <= B[j])
            arr[k++] = A[i++];
        else
        {
            arr[k++] = B[j++];
            inv_count += (mid - (i + low) + 1);
        }
    }

    while (i < A.size())
        arr[k++] = A[i++];
    while (j < B.size())
        arr[k++] = B[j++];

    return inv_count;
}

ll mergeSort(ll low, ll high)
{
    if (low == high)
        return 0;

    ll mid = low + ((high - low) >> 1);

    ll inv_count = 0;
    inv_count += mergeSort(low, mid);
    inv_count += mergeSort(mid + 1, high);
    inv_count += merge(low, mid, high);

    return inv_count;
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
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        cout << mergeSort(1, N) << endl;
    }
    return 0;
}
// END OF SOURCE CODE