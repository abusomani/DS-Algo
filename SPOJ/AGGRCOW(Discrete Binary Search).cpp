//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
Reading : https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/
Logic is to do a Binary Search over the range , for the possible GAPS. In the binary search, instead of validity of mid to a value
use a predicate / function to see , with given gap, how many cows can be assigned. 
If gap is small, increase the low to gap + 1
else decrease the high to gap

final answer is low - 1
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

bool isValid(vector<ll> &V, ll N, ll K, ll gap)
{
    ll assigned = 1, prev = V[0];
    for (int i = 1; i < N; i++)
    {
        if (V[i] - prev >= gap)
        {
            assigned++;
            prev = V[i];
        }
        if (assigned >= K)
            return true;
    }
    return (assigned >= K);
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
        cin >> N >> K;
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);

        sort(V.begin(), V.end());
        ll lowGap = 0, highGap = (V[N - 1] - V[0]);
        while (lowGap < highGap)
        {
            ll presentGap = lowGap + ((highGap - lowGap) >> 1);
            if (isValid(V, N, K, presentGap))
                lowGap = presentGap + 1;
            else
                highGap = presentGap;
        }
        cout << (lowGap - 1) << endl;
    }
    return 0;
}
// END OF SOURCE CODE