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

vector<ll> LuckyNums;

void process(string val)
{
    if (val.size() >= 3)
        return;

    val += '4';
    LuckyNums.push_back(stoll(val));
    process(val);
    val.pop_back(); // backtrack
    val += '7';
    LuckyNums.push_back(stoll(val));
    process(val);
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    process("");
    ll N;
    cin >> N;
    bool isValid = false;
    for (int i = 0; i < LuckyNums.size(); i++)
        if (N % LuckyNums[i] == 0)
            isValid = true;

    if (isValid)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
// END OF SOURCE CODE