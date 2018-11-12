//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    To make a permutation from given inversion sequence:
    READING : http://mathonline.wikidot.com/generating-permutations-with-inversion-sequences
    Let A={1,2,...,n} be a finite n-element set of positive integers and consider the inversion sequence (ai)ni=1=(a1,a2,...,an). 
    Set up an empty n-permutation (∗,∗,...,∗) where each ∗ represents a remaining position in the n-permutation. 
    The number 1 in to be placed in the (a1+1)th remaining position. 
    The number 2 in to be placed in the (a2+1)th remaining position. 
    The number k in to be placed in the (ak+1)th remaining position. 
    We continue this process and the number n is to be placed in the last remaining position.

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
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K, x;
        cin >> N;
        vector<ll> arr;
        arr.push_back(0);
        for (int i = 0; i < N; i++)
            cin >> x, arr.push_back(x);
        multimap<ll, ll> MpAtoInversion;
        for (int i = 1; i <= N; i++)
            cin >> x, MpAtoInversion.insert(make_pair(arr[i], x)), arr[i] = -1;

        for (multimap<ll, ll>::iterator it = MpAtoInversion.begin(); it != MpAtoInversion.end(); it++)
        {
            pair<ll, ll> P = *it;
            ll remainingPosition = P.second + 1;
            ll cnt = 1, i = 1;
            while (true)
            {
                if (arr[i] == -1)
                    cnt++;
                if (cnt > remainingPosition)
                    break;
                i++;
                if (i > N)
                    i = 1;
            }
            arr[i] = P.first;
        }
        for (int i = 1; i <= N; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// END OF SOURCE CODE