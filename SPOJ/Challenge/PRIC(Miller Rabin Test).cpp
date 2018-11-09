//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const ll MOD = 2147483648;
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
bool miillerTest(ll d, ll n) 
{ 
    ll a = 2 + rand() % (n - 4); 
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
  
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    return false; 
} 
  
bool isPrime(ll n, ll k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
    ll d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
    for (ll i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
    return true; 
} 
int main()
{
    fastio;
    ll x = 1;
    cout<<0;
    for(int i=1;i<=9999999;i++)
    {
        x = (x + 1234567890)%MOD;
        if(isPrime(x,7))cout<<1;
        else cout<<0;
    }
    return 0;
}
// END OF SOURCE CODE