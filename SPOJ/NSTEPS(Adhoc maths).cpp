//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll T;
    cin>>T;
    while(T--)
    {
        ll N,K,x,y;
        cin>>x>>y;

        if(x%2 == 0 and ((x == y+2) or (x == y))) cout<<(x+y)<<endl;
        else if(x%2 == 1 and ((x == y+2) or (x == y))) cout<<(x+y-1)<<endl;
        else cout<<"No Number"<<endl;

    }
    return 0;
}
// END OF SOURCE CODE