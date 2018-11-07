//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Quick Find implies, find has minimal operations. i.e. when uniting always store id as the component id
    Eager approach :
    The id array represents the component in which the node is. So, find is just return of id[i]
    and connectivity check is id[i] == id[j]

    Disadvantage : Union takes O(N) time in worst case per operaton.
    So for N unions, O(N^2) operations will take place.
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

ll find(ll a)
{
    return id[a];
}

// union is a keyword so use some other word
void unite(ll a, ll b, ll N)
{
    // Change all id of A to id of B ( not hard and fast)
    ll idOfA = find(a), idOfB = find(b);
    for (int i = 0; i < N; i++)
        if (id[i] == idOfA) // Dont write id[a] here, as it might change and it will screw up the code.
            id[i] = idOfB;
}

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N; // number of nodes
    cin >> N;
    for (int i = 0; i < N; i++)
        id[i] = i;
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
8 9
5 0
7 2
6 1

Output should be:
1 1 1 8 8 1 1 1 8 8
*/