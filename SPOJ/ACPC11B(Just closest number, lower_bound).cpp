//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Closest number can be found using lower_bound and corner cases
    if x <= a[0]
    if x >= a[N-1]
    index from lower_bound is 0 
    index between 0 to N
*/
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
vector<ll> A, B;

ll findClosestDifference(ll X) // closest in vector B
{
    //CORNER CASES
    if (X <= B[0])
        return abs(B[0] - X);

    if (X >= B[B.size() - 1])
        return abs(X - B[B.size() - 1]);

    ll idx = lower_bound(B.begin(), B.end(), X) - B.begin(); // greater than equal to X

    if (idx == 0)
        return abs(B[idx] - X);

    if (idx > 0 and idx < B.size())
        return min(abs(B[idx] - X), abs(B[idx - 1] - X));
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
        A.clear();
        B.clear();
        ll N, M, x;
        cin >> N;
        for (int k = 0; k < N; k++)
            cin >> x, A.push_back(x);

        cin >> M;
        for (int k = 0; k < M; k++)
            cin >> x, B.push_back(x);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        ll ans = INF;
        for (int i = 0; i < A.size(); i++)
        {
            ll a = A[i];
            ans = min(ans, findClosestDifference(a));
        }
        cout << ans << endl;
    }

    return 0;
}
// END OF SOURCE CODE