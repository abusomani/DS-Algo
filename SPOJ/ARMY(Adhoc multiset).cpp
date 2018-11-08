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

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, M, x;
        cin >> N >> M;
        multiset<ll> God, MechaGod;

        for (int i = 1; i <= N; i++)
            cin >> x, God.insert(x);
        for (int i = 1; i <= M; i++)
            cin >> x, MechaGod.insert(x);

        while (!God.empty() and !MechaGod.empty())
        {
            ll aVal = *(God.begin()), bVal = *(MechaGod.begin());
            if (aVal == bVal) // if both of the army have same weakest, delete from mechagod's army
            {
                MechaGod.erase(MechaGod.begin());
            }
            else
            {
                if (aVal < bVal)
                    God.erase(God.find(aVal));
                else
                    MechaGod.erase(MechaGod.find(bVal));
            }
        }

        if (N == 0 and M == 0)
            cout << "uncertain" << endl;
        else if (!God.empty())
            cout << "Godzilla" << endl;
        else if (!MechaGod.empty())
            cout << "MechaGodzilla" << endl;
    }
    return 0;
}
// END OF SOURCE CODE