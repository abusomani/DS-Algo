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
    cin>>T;
    string s;
    while(T--)
    {
        ll N,K = 0,student,candy;
        cin>>student; 
        N = student;
        while(student--) 
        {
            cin>>candy;
            K = (K + candy)%N;
        }
        if(K == 0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;  
    }
    return 0;
}
// END OF SOURCE CODE