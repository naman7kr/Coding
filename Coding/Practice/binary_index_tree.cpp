#include <bits/stdc++.h>
#define MAX 100000
using namespace std;



void update(int *bt,int a[],int n,int pos,int value){
	pos++;
	while(pos<=n){
		bt[pos]+=value;
		pos+=(pos&(-pos));
	}
}
int getSum(int* bt,int pos){
	pos++;
	int sum=0;
	while(pos>0){
		sum+=bt[pos];
		pos-=(pos&(-pos));
	}
	return sum;
}

void constructBT(int *bt,int a[],int n){
	for(int i=0;i<n;i++){
		update(bt,a,n,i,a[i]);
	}
}

main(){
	int n ;
	 cin>> n;
	 int a[MAX];
	 for(int i=0;i<n;i++)cin>>a[i];
	 int* bt=new int[MAX];
	 constructBT(bt,a,n);
	 int t;
	cin>>t;
	while(t--){
		int cse;//0->sum 1->update
		cin>>cse;
		if(cse==0){
			int pos;
			cin>>pos;
			pos--;
			cout<<getSum(bt,pos);
		}else{
			int val,pos;
			cin>>val>>pos;
			int diff=val-a[pos-1];
			pos--;
			update(bt,a,n,pos,diff);
		}
	}
}