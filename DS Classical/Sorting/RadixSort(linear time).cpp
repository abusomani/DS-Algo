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

const ll MAX_SIZE = 20000005;

ll arr[MAX_SIZE];
ll N;

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

void countingSort(ll digitNumber)
{
    vector<ll> V[10];

    /*
        If a number N  is ABCDEFGH
        Getting the digit C means
        N %= pow(10,digitNumber)
        N /= pow(10, digitNumber - 1)
    */

    ll divideWith = power(10, digitNumber - 1);
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
    arr[0] = -1;
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        radixSort();

        for (int i = 1; i <= N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE