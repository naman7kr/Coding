#include <bits/stdc++.h>
using namespace std;
int x,y,d;
void extended_euclidean(int a,int b){
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

int main(){
	int a,m;
	scanf("%d%d",&a,&m);

	//brute force-check for all numbers 0 to m-1

	//Extended Euclidean method
	extended_euclidean(a,m);
	if(d==1){
		printf("Inverse is %d\n",(x%m+m)%m);
	}else{
		printf("Inverse does not exists\n");
	}
	return 0;
}