#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod %1000000007

ll power(ll a, ll n){
	if(n==0)return 1;
	if(n%2==0){
		int p=power(a,n/2);
		return (p*p)mod;
	}else{
		return (power(a,n-1)*a)mod;
	}
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
		ll dif=abs(a-b);
		
		ll sum=(power(a,n)+power(b,n))mod;
		if(dif==0)
			{
				cout<<(sum)mod<<"\n";
				continue;
			}
			if(sum==0){
				cout<<(dif)mod<<"\n";
				continue;
			}

		cout<<__gcd(dif,sum)mod<<"\n";
	}
}