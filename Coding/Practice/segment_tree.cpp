#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int constructST(int a[],int ss,int se,int* st,int pos){
	if(ss==se){
		st[pos]=a[ss];
		return a[ss];	
	}
	int mid=ss+(se-ss)/2;
	st[pos]=constructST(a,ss,mid,st,2*pos+1)+constructST(a,mid+1,se,st,2*pos+2);
	return st[pos];
} 
int getSum(int* st,int l , int r,int ss,int se,int pos){
	if(l<=ss&&r>=se){
		return st[pos];
	}
	if(se<l||ss>r)
		return 0;
	int mid=ss+(se-ss)/2;
	return getSum(st,l,r,ss,mid,2*pos+1)+getSum(st,l,r,mid+1,se,2*pos+2);
}
void update(int a[],int * st,int ss,int se,int pos,int p,int value){
	if(p<ss||p>se)return;
	st[pos]=st[pos]+value;
	if(ss!=se){
		int mid=ss+(se-ss)/2;
		update(a,st,ss,mid,2*pos+1,p,value);
		update(a,st,mid+1,se,2*pos+2,p,value);
	}
}
main(){
	int n;
	cin>>n;
	int a[MAX];
	int *st=new int[MAX];
	for(int i=0;i<n;i++) cin>> a[i];
	constructST(a,0,n-1,st,0);
	int t;
	cin>>t;
	while(t--){
		int l,r,d,i;
		char c;
		cin>>c;
		if(c=='s'){
			cin>>l>>r;
			cout<<getSum(st,--l,--r,0,n-1,0);
		}else{
			cin>>d>>i;
			d--;
			int diff=i-a[d];
			a[d]=i;
			update(a,st,0,n-1,0,d,diff);
		}
	}
}