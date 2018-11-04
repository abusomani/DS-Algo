// @BEGIN OF SOURCE CODE
#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MAX 100005
#define LIM 300005
#define PrimeRange 1000006
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long ll;
typedef long double LD;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;


ll MOD = 1000000007;
ll INF = 1e18;
LD  EPS   = 1e-10;
LD PI = acos(-1.0);
template<typename T> T gcd(T a, T b){return (b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T mod_neg(T a, T b) {return ((a%b)+b)%b;}
ll mulmod(ll a,ll b, ll m){ll q=(ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1%m,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
bool Pvisit[PrimeRange];vector<int> Primes;
bool isPrime(int N){
	for(int i=2;i<=sqrt(N);i++)if(N%i == 0)return false; return true;
}
void mark(int N)
{	for(int i= N*N; i<PrimeRange; i += N)Pvisit[i] = false;}
void sieve()
{	memset(Pvisit,true,PrimeRange);Pvisit[1] = false;Primes.push_back(2);mark(2);
	for(int i=3; i<=sqrt(PrimeRange); i += 2)if(Pvisit[i] == true)Primes.push_back(i),mark(i);
	for(int i=1001;i<PrimeRange;i += 2)if(isPrime(i))Primes.push_back(i),Pvisit[i]=true;
}
int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

/* This function calculates (a^b)%MOD */
ll pow(ll a, ll b, ll MOD)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long factMOD(int n, int MOD)
{
    long long res = 1;
    while (n > 0)
    {
        for (int i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

long long C(int n, int r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
struct cmp1 {
	bool operator() (const ll &x ,const ll &y) const
	{
		return x < y;
	}
};

struct cmp2{
		bool operator() (const ll &x ,const ll &y) const
		{
			return x > y;
		}
};
ll seriesSummation(ll r,ll M, ll MD)
{
	if(M <= 2)
	{
		if(M == 1)return 1;
		else return(1 + r)%MD;
	}
	else
	{
		ll val = 0;
		if(M%2)
		val = (val + pow(r,M-1,MD))%MD;
		return (val + ((1 + r)%MD * seriesSummation((r*r)%MD,M/2,MD)%MD))%MD;
	}

}
int computeZ(string s)
{
	ll n = s.size();
	ll z[n+3];
	ll l = 0 ,  r = 0;
	for(int i = 1; i < n;i++)
	{
		if(i > r)
		{
			l = r = i;
			while(r < n and s[r-l] == s[r]) r++;
			z[i] = (r-l);
			r--;
		}
		else
		{
			int k = i - l;
			if(z[k] < r - i + 1)
			z[i] = z[k];

			else
			{
				l = i;
				while(r < n and s[r-l] == s[r])r++;
				z[i] = (r-l);
				r--;
			}
		}
	}

}
int main()
{
 	fastio;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//sieve();
	ll N;
	while(cin>>N and N != 42) cout<<N<<endl;

 	return 0;
}
// END OF SOURCE CODE

