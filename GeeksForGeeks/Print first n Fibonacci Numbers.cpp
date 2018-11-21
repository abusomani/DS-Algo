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
vector<ll> DPFib;

void preprocess()
{
    DPFib.push_back(1);
    DPFib.push_back(1);
    for (int i = 2; i <= 105; i++)
        DPFib.push_back(DPFib[i - 1] + DPFib[i - 2]);
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    preprocess();
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        for (int i = 0; i < N; i++)
            cout << DPFib[i] << " ";
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE