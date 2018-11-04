#include <bits/stdc++.h>
using namespace std;
#define ll long long
void factorial(ll N) {
	string ans = "1";
	ll sm = 0 , carry = 0;
	for(ll i=2;i<=N;i++) {
		ll j = 0;
		while(j <  ans.size()) {
			sm = (ans[j] - '0')*i + carry;
			carry = sm / 10;
			sm = sm %10;
			ans[j++] = (char)(sm + '0');			
		}
		while(carry) {
			char c = (char)(carry%10 + '0');
			ans.push_back(c);
			carry /= 10;
		}
	}
	reverse(ans.begin(), ans.end());	
	cout<<ans<<endl;
}

int main() {
	ll T;
	cin>>T;
	while(T--)
	{
		ll N,K,x;
		cin>>N;
		factorial(N);
	}
	return 0;
}
