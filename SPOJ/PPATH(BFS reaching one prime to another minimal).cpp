//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Travel from one prime to another in minimal steps.
    It is same as source to destination so we can use BFS.
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

unordered_map<ll, pair<bool, string>> FourDigitPrimes;

bool isPrime(ll N)
{
    if (N <= 1)
        return false;
    if (N <= 3)
        return true;
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
            return false;

    return true;
}

bool visited[10005];
void preprocess()
{
    for (int i = 1000; i <= 9999; i++)
        FourDigitPrimes[i] = make_pair(isPrime(i), to_string(i));
}

ll BFS(ll src, ll dest)
{
    memset(visited, false, sizeof(visited));
    queue<pair<ll, ll>> Q;
    Q.push(make_pair(src, 0));

    while (!Q.empty())
    {
        pair<ll, ll> P = Q.front();
        Q.pop();
        visited[P.first] = true;

        if (P.first == dest)
            return P.second;

        string str = FourDigitPrimes[P.first].second;
        for (int i = 0; i < str.size(); i++)
        {
            string temp = str;
            for (char ch = '0'; ch <= '9'; ch++)
            {
                temp[i] = ch;
                ll num = stoll(temp);
                if (!visited[num] and FourDigitPrimes[num].first)
                    Q.push(make_pair(num, P.second + 1));
            }
        }
    }
    return -1;
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
        ll N, M, K, x;
        cin >> N >> M;
        ll ans = BFS(N, M);
        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
// END OF SOURCE CODE