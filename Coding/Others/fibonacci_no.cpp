#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll f0=0;
ll f1=1;
ll fib(ll n);
void power(ll f[2][2],ll n);
void multiply(ll f[2][2],ll m[2][2]);


//[f(n) f(n-1)]=[1 1 ^(n-1)*[f(1) f(0)]  
//				 1 0]
main(){
	ll n;
	cin>>n;
	cout<<fib(n-1);
}


ll fib(ll n){
	if(n==0||n==-1){
		return 0; 
	}
	ll f[2][2]={{1,1},{1,0}};

	power(f,n-1);

	return (f[0][0]);
}

void power(ll f[2][2], ll n){
	ll m[2][2] = {{1,1},{1,0}};
	if(n==0||n==1){
		return;
	}
	if(n%2==0){
		power(f,n/2);
		multiply(f,f);
		}
	else {
		power(f,n-1);
		multiply(f,m);
	}
}
void multiply(ll f[2][2],ll m[2][2]){
	ll w=f[0][0]*m[0][0]+f[0][1]*m[1][0];
	ll x=f[0][0]*m[0][1]+f[0][1]*m[1][1];
	ll y=f[1][0]*m[0][0]+f[1][1]*m[1][0];
	ll z=f[1][0]*m[0][1]+f[1][1]*m[1][1];
	f[0][0]=w;
	f[0][1]=x;
	f[1][0]=y;
	f[1][1]=z;
}