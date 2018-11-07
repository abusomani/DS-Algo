//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Weighted quick union as name implies take minimal operation in union i.e. make parent of j as parent of i but based on weights ( size of existing tree)
    Here "parent of x" has recursive meaning
    Approach :
    The id array represents the parent of the node is. So, find is recursive till id[i] == i

    While union operation, make the smaller tree child of larger tree. ( to have less sized resultant trees)

    Advantage : Find takes O(logN) time in worst case per operaton. Union goes to O(logN) time
    Disadvantage : Uses extra O(N) space for size
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000005;
ll id[MAX];
ll sz[MAX];

// loop till we get ultimate parent
ll find(ll a)
{
    ll parent = id[a];
    while (id[parent] != parent)
        parent = id[parent];
    return parent;
}

// union is a keyword so use some other word
void unite(ll a, ll b, ll N)
{
    // change parents according to size
    ll parentOfA = find(a), parentOfB = find(b);
    if (sz[parentOfA] < sz[parentOfB])
        id[parentOfA] = id[parentOfB], sz[parentOfB] += sz[parentOfA];
    else
        id[parentOfB] = id[parentOfA], sz[parentOfA] += sz[parentOfB];
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N; // number of nodes
    cin >> N;
    for (int i = 0; i < N; i++)
        id[i] = i, sz[i] = 1;
    ll T;
    cin >> T; // number of operations
    while (T--)
    {
        ll a, b;
        cin >> a >> b;
        // Operation is if a and b are not in same component do a unite else nothing

        if (find(a) == find(b))
            cout << "Already connected" << endl;
        else
        {
            unite(a, b, N);
            cout << "Now connected" << endl;
        }
        for (int i = 0; i < N; i++)
            cout << i << " : " << id[i] << endl;
    }

    return 0;
}
// END OF SOURCE CODE
/*
Sample input :
10
9
4 3
3 8
6 5
9 4
2 1
5 0
7 2
6 1
7 3

Output should be:
6 2 6 4 6 6 6 2 4 4
*/