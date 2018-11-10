//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Majority element : Moore's voting algorithm
    consider first element as major, loop through array, if arr[i] is same as major then cnt ++
    else cnt-- and if at any count is zero then consider that element as major and cnt = 1
*/
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
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        ll arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        if (N == 0)
            cout << "NO" << endl;
        else
        {
            ll majority_element = arr[0], cnt = 1;
            for (int i = 1; i < N; i++)
            {
                if (arr[i] == majority_element)
                    cnt++;
                else
                {
                    cnt--;
                    if (cnt == 0)
                    {
                        majority_element = arr[i];
                        cnt = 1;
                    }
                }
            }
            if (cnt)
            {
                cnt = 0;
                for (int i = 0; i < N; i++)
                    if (arr[i] == majority_element)
                        cnt++;
                if (2 * cnt > N)
                    cout << "YES " << majority_element << endl;
                else
                    cout << "NO" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
// END OF SOURCE CODE