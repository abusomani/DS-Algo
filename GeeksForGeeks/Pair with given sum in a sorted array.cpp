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
        vector<ll> V;
        for (int i = 0; i < N; i++)
            cin >> x, V.push_back(x);
        cin >> K; // desired sum
        ll cnt = 0;
        ll left = 0, right = N - 1;

        while (left < right)
        {
            ll val = V[left] + V[right];
            if (val == K)
                cnt++, cout << V[left++] << " " << V[right--] << " " << K << endl;
            else if (val < K)
                left++;
            else
                right--;
        }
        if (!cnt)
            cout << -1 << endl;
    }
    return 0;
}
// END OF SOURCE CODE