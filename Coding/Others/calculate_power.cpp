#include <bits/stdc++.h>
using namespace std;
#define ll long long 
 //calculate x^n

//long method
ll longMethodPow(ll x, ll n){
	if(n==0){
		return 1;
	}else{
		return x*longMethodPow(x,n-1);
	}
}
//short method
ll shortMethodPow(ll x, ll n){
	if(n==0){
		return 1;
	}else if(n%2==0){
		ll y=shortMethodPow(x,n/2);
		return y*y;
	}else{
		return x*shortMethodPow(x,n-1);
	}
}
main(){
	ll x;
	cin>>x;
	ll n;
	cin>>n;
	cout<<"Output by O(n):"<<longMethodPow(x,n)<<"\n";
	cout<<"Output by O(log(n)):"<<shortMethodPow(x,n)<<"\n";
}