#include <bits/stdc++.h>
using namespace std;

int x,y,d;
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}
void extended_euclidean(int a,int b){
	if(a==0){
		x = 1;
		y = 0;
		d=b;
	}
	else{
		extended_euclidean(b%a,a);
		int temp = x;
		x = y;
		y = temp - (b/a)*y;
	}
	

}
int main(){
	int a,b;
	cin>>a>>b;
	printf("%d\n",gcd(a,b));
	extended_euclidean(a,b);
	printf("%d x=%d y=%d\n",d,x,y);
	return 0;
}