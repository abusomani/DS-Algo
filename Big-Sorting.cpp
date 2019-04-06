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

bool comp(string a, string b)
{
    if (a.size() < b.size())
        return true;
    else if (a.size() > b.size())
        return false;
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            ll aV = (a[i] - '0');
            ll bV = (b[i] - '0');
            if (aV == bV)
                continue;
            return (aV < bV);
        }
        return true;
    }
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted)
{
    sort(unsorted.begin(), unsorted.end(), comp);
    return unsorted;
}

int main()
{
    fastio;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++)
    {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
// END OF SOURCE CODE