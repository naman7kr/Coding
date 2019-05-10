#include <bits/stdc++.h>
using namespace std;

void rotate_left(int a[],int n,int d){
	for(int i=1;i<=__gcd(n,d);i++){
		int temp=a[i];
		int j=i;
		int k;
		while(1){
			k=j+d;
			if(k>n){
				k=k-n;
			}
			if(k==i){
				a[j]=a[k];
				break;
			}
			a[j]=a[k];
			j=k;
		}
		a[j]=temp;
	}
}
void rotate_right(int a[],int n,int d){
	if(d>n)d=d%n;
	for(int i=1;i<=__gcd(d,n);i++){
		int temp=a[i];
		int j=i;
		int k;
		while(1){
			k=j+d;
			if(k>n)k=k-n;
			if(k==i){
				a[k]=temp;
				break;
			}
			int p=a[k];
			a[k]=temp;
			j=k;
			temp=p;
		}
	}
}
main(){
	int n;
	cin>>n;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k;cin>>k;
	rotate_right(a,n,k);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}