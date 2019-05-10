#include <bits/stdc++.h>
using namespace std;
int x,y,d;
int extended_euclidean(int a, int b){
	if(a==0){
		x=0;
		y=1;
		d=b;
	}else{
		extended_euclidean(b%a,a);
		int temp = y;
		y=x;
		x=temp-(b/a)*x;
	}
}
int mod_inverse(int b, int m){
	extended_euclidean(b,m);
	if(d!=1)
		return -1;
	return ((x%m+m)%m);
}

int mod_division(int a,int b, int m){
	int b_inv = mod_inverse(b,m);
	if(b_inv==-1){
		return -1;
	}
	return ((a%m)*(b_inv%m))%m;

}

int main(){
	int a,b,m;
	scanf("%d%d%d",&a,&b,&m);

	//a/b (mod m)
	int div = mod_division(a,b,m);
	if(div==-1)
		cout<<"Division not defined";
	else{
		cout<<div;
	}
	

	return 0;
}