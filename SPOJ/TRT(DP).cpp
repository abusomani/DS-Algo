//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
READING : https://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-DP-besides-the-TopCoder-tutorial/answer/Michal-Danil%C3%A1k
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
const ll MAX_SIZE = 2005;

ll N;
ll dp[MAX_SIZE][MAX_SIZE];
ll arr[MAX_SIZE];

/*
    Problem statement now mean, what is the best profit when current year is age
    and the unsold wines are in interval [left, right]
*/
ll recurDP(ll left, ll right)
{
    if (left > right)
        return 0;

    // DP Saviour
    if (dp[left][right] != -1)
        return dp[left][right];

    ll age = (N - (right - left + 1) + 1); // computed from number of unsoled
    return (dp[left][right] = max(age * arr[left] + recurDP(left + 1, right), age * arr[right] + recurDP(left, right - 1)));
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << recurDP(0, N - 1);

    return 0;
}
// END OF SOURCE CODE