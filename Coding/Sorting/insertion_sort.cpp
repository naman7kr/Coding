#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int k=*a;
	*a=*b;
	*b=k;
}
//20 30 40 10 5
void insertion_sort(int a[],int n){

	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(a[j+1]<a[j]){
				swap(&a[j+1],&a[j]);
			}else{
				break;
			}
		}
		for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
}

main(){
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion_sort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}