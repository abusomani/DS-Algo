//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    minimum difference between two unsorted array can be found by merging step of arrays after sorting
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
        int i = 0, j = 0;

        while (i < A.size() and j < B.size())
        {
            ans = min(ans, abs(A[i] - B[j]));
            if (A[i] <= B[j])
                i++;
            else
                j++;
        }

        cout << ans << endl;
    }

    return 0;
}
// END OF SOURCE CODE