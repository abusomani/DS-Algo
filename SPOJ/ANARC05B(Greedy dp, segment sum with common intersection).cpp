//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Finding maximum sum, given you can switch between two sequences at common intersection point. ( strictly increasing )
    Greedy and DP both are applicable. But greedy is easy, by using two pointers because, we need maximum of individual segments
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 100005;

struct Helix
{
    ll val;
    ll sm;
};
Helix A[MAX_SIZE], B[MAX_SIZE];

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N, M;
    while (cin >> N, N)
    {
        ll sm = 0;
        for (int i = 1; i <= N; i++)
            cin >> A[i].val, sm += A[i].val, A[i].sm = sm;
        cin >> M;
        sm = 0;
        for (int i = 1; i <= M; i++)
            cin >> B[i].val, sm += B[i].val, B[i].sm = sm;

        //insert last common Node
        A[N + 1].val = MOD;
        A[N + 1].sm = MOD + A[N].sm;
        B[M + 1].val = MOD;
        B[M + 1].sm = MOD + B[M].sm;

        //Two pointers for traversing
        // last_sum variables to store the last sum added from individual sequences
        ll first = 1, second = 1, ans = 0, last_sum_first = 0, last_sum_second = 0;

        while (first <= (N + 1) and second <= (M + 1))
        {
            if (A[first].val < B[second].val)
                first++;
            else if (A[first].val > B[second].val)
                second++;
            else
            {
                ll fSum = A[first].sm - last_sum_first;
                ll sSum = B[second].sm - last_sum_second;
                ans += max(fSum, sSum);
                last_sum_first = A[first++].sm;
                last_sum_second = B[second++].sm;
            }
        }
        cout << (ans - MOD) << endl;
    }
    return 0;
}
// END OF SOURCE CODE