//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    While merge , if there are no inversions, that means all elements of A are smaller than B.
    If inversion is there at ith position in A that means, (mid - A[i].second) inversions would be there as all elements from i to mid are greater than jth of B
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

ll merge(ll arr[], ll low, ll mid, ll high)
{
    vector<ll> A, B;
    for (int i = low; i <= mid; i++) // i starts from low
        A.push_back(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        B.push_back(arr[i]);

    ll i = 0, j = 0, k = low, inv_count = 0; // here i has become 0

    while (i < A.size() and j < B.size())
    {
        if (A[i] <= B[j])
            arr[k++] = A[i++];
        else
        {
            arr[k++] = B[j++];
            inv_count += (mid - (i + low) + 1); // (i + low) is the index of the actual element
        }
    }
    while (i < A.size())
        arr[k++] = A[i++];
    while (j < B.size())
        arr[k++] = B[j++];

    return inv_count;
}

ll mergeSort(ll arr[], ll low, ll high) // to count inversions
{
    if (low == high)
        return 0;
    ll mid = low + ((high - low) >> 1);
    ll inv_count = 0;
    inv_count += mergeSort(arr, low, mid);
    inv_count += mergeSort(arr, mid + 1, high);
    inv_count += merge(arr, low, mid, high);
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
        ll N;
        cin >> N;
        ll arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        ll inversions = mergeSort(arr, 0, N - 1);

        cout << inversions << endl;
    }

    return 0;
}
// END OF SOURCE CODE