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

void merge(ll arr[], ll low, ll mid, ll high)
{
    vector<ll> A, B;
    for (int i = low; i <= mid; i++)
        A.push_back(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        B.push_back(arr[i]);

    int i = 0, j = 0, k = low;
    while (i < A.size() and j < B.size())
    {
        if (A[i] <= B[j])
            arr[k++] = A[i++];
        else
            arr[k++] = B[j++];
    }
    while (i < A.size())
        arr[k++] = A[i++];
    while (j < B.size())
        arr[k++] = B[j++];
}

void mergeSort(ll arr[], ll low, ll high)
{
    if (low < high) // low == high means one element, one element does not need sorting
    {
        ll mid = low + ((high - low) >> 1);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N;
    cin >> N;
    ll arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    mergeSort(arr, 0, N);

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}
// END OF SOURCE CODE