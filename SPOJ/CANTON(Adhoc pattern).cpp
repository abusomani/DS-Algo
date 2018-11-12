//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Diagonal arguments. Better preprocess a NxN array with same pattern and store it.
    if first row, move right and then diagonal down
    if first column, move down and then diagonal up
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX_SIZE = 5005;

vector<string> Ans;
void preprocess()
{
    Ans.push_back("0");
    int i = 1, j = 1;
    bool diagonalUp = false;
    while (i < MAX_SIZE and j < MAX_SIZE)
    {
        if (i == 1)
            Ans.push_back(to_string(i) + "/" + to_string(j)), j++, diagonalUp = false;
        if (j == 1)
            Ans.push_back(to_string(i) + "/" + to_string(j)), i++, diagonalUp = true;
        if (diagonalUp)
            Ans.push_back(to_string(i) + "/" + to_string(j)), i--, j++;
        if (!diagonalUp)
            Ans.push_back(to_string(i) + "/" + to_string(j)), i++, j--;
    }
}

int main()
{
    fastio;
    preprocess();
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        cout << "TERM " << N << " IS " << Ans[N] << endl;
    }
    return 0;
}
// END OF SOURCE CODE