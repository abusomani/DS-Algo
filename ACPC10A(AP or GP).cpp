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
    while(true)
    {
        ll N,K,a,b,c;
        cin>>a>>b>>c;

        if(a == 0 and b == 0 and c == 0)break;
        else if(c-b == b-a) cout<<"AP "<<c+(c-b)<<endl;
        else if(b*b == a*c) cout<<"GP "<<c*c /b <<endl;
    }
    return 0;
}
// END OF SOURCE CODE