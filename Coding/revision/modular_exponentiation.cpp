#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod_exp_rec(int a,int b,int m){
	if(b==0){
		return 1;
	}else if (b%2==0){
		int y = mod_exp_rec(a,b/2,m);
		return ((y*y)%m);
	}else{
		return (((a%m)*mod_exp_rec(a,b-1,m))%m);
	}
}
ll mod_exp_iterative(ll a,ll b,ll m){
	ll res = 1;
	a = a%m;
	while(b>0){
		if(b&1){
			res = (res * a)%m;
		}
		b=b>>1;
		a = (a * a)%m;
	}
	return res;
}
int main(){
	ll a,b,m;
	cin>>a>>b>>m;
	cout<<mod_exp_rec(a,b,m)<<"\n";
	cout<<mod_exp_iterative(a,b,m);
	return 0;
}