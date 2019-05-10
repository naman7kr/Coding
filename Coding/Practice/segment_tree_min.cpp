#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int construct_ST(int* st,int a[], int ss,int se,int pos){
	if(ss==se){
		st[pos]=a[ss];
		return a[ss];
	}
	int mid= ss+(se-ss)/2;
	st[pos]=min(construct_ST(st,a,ss,mid,2*pos+1),construct_ST(st,a,mid+1,se,2*pos+2));
	return st[pos];
}
int getMin(int * st,int ss,int se,int l,int r, int pos){
	if(l<=ss&&r>=se)
		return st[pos];
	if(l>se||r<ss)
		return INT_MAX;
	int mid=ss+(se-ss)/2;
	return min(getMin(st,ss,mid,l,r,2*pos+1),getMin(st,mid+1,se,l,r,2*pos+2));


}
main(){
	int n;
	cin>>n;
	int a[MAX];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int* st = new int[2*(1<<(int)(ceil(log2(n))))];
	construct_ST(st,a,0,n-1,0);

	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;r--;
		cout<<getMin(st,0,n-1,l,r,0);
	}
}