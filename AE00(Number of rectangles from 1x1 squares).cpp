//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    T = 1;
    while(T--)
    {
        ll N,K,x;
        cin>>N;
        ll ans = 0;
        for(int i=1;i<=sqrt(N);i++) {
            ll high_side = N / i;
            if(high_side >= i) {
                ans += (high_side - i + 1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// END OF SOURCE CODE