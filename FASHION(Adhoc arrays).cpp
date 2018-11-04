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
        ll N,K = 0,x;
        cin>>N;
        ll A[N], B[N];
        for(int i=0;i<N;i++)cin>>A[i];
        for(int i=0;i<N;i++)cin>>B[i];

        sort(A,A+N); sort(B,B+N);

        for(int i=0;i<N;i++) K += A[i]*B[i];

        cout<<K<<endl;

    }
    return 0;
}
// END OF SOURCE CODE
