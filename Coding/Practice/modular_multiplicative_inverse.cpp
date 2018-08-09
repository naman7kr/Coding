#include <bits/stdc++.h>
using namespace std;
#define modm %m

int power(int a,int b,int m){
	if(b==0){
		return 1;
	}
	int p=power(a,b/2,m)modm;
	p=(p*p)modm;
	return ((!(b&1))?p:(a*power(a,b-1,m))modm);
}

int modular_multiplicative_invers(int a,int m){
	if(__gcd(a,m)!=1)return -1;
	return power(a,m-2,m);	
}

main(){
	int a,m;
	cin>>a>>m;
	cout<<modular_multiplicative_inverse(a,m);
}