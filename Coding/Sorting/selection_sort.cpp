#include <bits/stdc++.h>
using namespace std;
const int mx=100000;

void selectionSort(int v[],int n){
	for(int i=0;i<n;i++){
		int mn=mx;
		int pos=0;
		for(int j=i;j<n;j++){
			if(v[j]<mn){
				mn=v[j];
				pos=j;
			}
		}
		int k=v[pos];
		v[pos]=v[i];
		v[i]=k;
	}
	cout<<"\n";
}

main(){
	int n;
	cin>>n;
	int v[100000];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	selectionSort(v,n);
	
	for( int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}