#include <bits/stdc++.h>
using namespace std;
void heapify(int a[],int n, int i){
	int l=2*i+1,r=2*i+2;
	int min;
	if(l<=n&&a[i]>a[l]){
		min=l;
	}else{
		min=i;
	}
	if(r<=n&&a[min]>a[r]){
		min=r;
	}
	if(i!=min){
		a[min]=a[min]^a[i];
		a[i]=a[min]^a[i];
		a[min]=a[min]^a[i];
		heapify(a,n,min);
	}
}
int pop_min(int a[],int &heap_size){
	int t=a[0];
	a[0]=a[heap_size];
	a[heap_size]=t;
	heapify(a,heap_size-1,0);
	
	return a[heap_size];
}
int solve(int a[],int n, int i){
	int heap_size=n-1-i;
	int k=pop_min(a,heap_size);
	return k;
}


void build_min_heap(int a[],int n){
	for(int i=n/2;i>=0;i--)
		heapify(a,n-1,i);
}

main(){
	int n;
	cin>>n;
	int a[100];
	int k;
	for(int i=0;i<n;i++)cin>>a[i];
	build_min_heap(a,n);
	cin>>k;
	int mini;

	for(int i=0;i<k;i++){
		 mini=solve(a,n,i);
	}
	cout<<mini;



}