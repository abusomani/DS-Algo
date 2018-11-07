//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    RADIX SORT implementation is :
    find the element with max number of digits. That would be the number of passes
    for each pass from i = 1 to K ( where K is number of digits in max element)
        for each number in array
            1. mod the number with 10^digit
            2. divide the number by 10^(digit-1)

        This is done to get the bucket the number should go.
        Merge the buckets.

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 20000005;

ll arr[MAX_SIZE];
ll N, a, b, X1;

ll getMaxElement()
{
    ll mx = 0;
    for (int i = 1; i <= N; i++)
        mx = max(mx, arr[i]);
    return mx;
}

ll power(ll a, ll b)
{
    ll ans = 1, x = a;
    while (b)
    {
        if (b & 1)
            ans = (ans * x);
        x = (x * x);
        b >>= 1;
    }
    return ans;
}

void countingSort(ll digits)
{
    vector<ll> V[10];
    ll divideWith = power(10, digits - 1);
    ll modWith = 10 * divideWith;

    for (int i = 1; i <= N; i++)
    {
        ll val = arr[i] % modWith;
        ll dig = val / divideWith;
        V[dig].push_back(arr[i]);
    }
    ll j = 1;
    for (int i = 0; i < 10; i++)
    {
        for (vector<ll>::iterator it = V[i].begin(); it != V[i].end(); it++)
            arr[j++] = *it;
    }
}

void radixSort()
{
    ll max_elem = getMaxElement();
    ll digits = 0;
    while (max_elem)
        digits++, max_elem /= 10;

    for (int i = 1; i <= digits; i++)
        countingSort(i);
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
        cin >> N >> a >> b >> X1;
        arr[1] = X1;

        for (int i = 2; i <= N; i++)
            arr[i] = ((arr[i - 1] * a) % MOD + b) % MOD;

        radixSort();

        ll result = 0;
        for (int i = 1; i <= N; i++)
            result = (result + (arr[i] * i) % MOD) % MOD;
        cout << result << endl;
    }
    return 0;
}
// END OF SOURCE CODE