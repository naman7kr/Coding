#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll  power(int a,int b){
	if(b==0)return 1;
	if(!(b&1)){
		ll y=power(a,b/2);
		return y*y;
	}else{
		return a*power(a,b-1);
	}
}

main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b);
}