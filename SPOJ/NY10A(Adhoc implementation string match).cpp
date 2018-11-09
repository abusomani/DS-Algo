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

string patterns[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
map<string, ll> Mp;
ll Cnt[8];
void preprocess()
{
    memset(Cnt, 0, sizeof(Cnt));
    for (int i = 0; i < 8; i++)
        Mp.insert(make_pair(patterns[i], i));
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
        cin >> N;
        preprocess();
        string str;
        cin >> str;

        for (int i = 0; i <= str.size() - 3; i++)
        {
            string x = str.substr(i, 3);
            if (Mp.find(x) != Mp.end())
                Cnt[Mp[x]]++;
        }
        cout << N << " ";
        for (int i = 0; i < 8; i++)
            cout << Cnt[i] << " ";
        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE