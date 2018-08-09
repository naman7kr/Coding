#include <bits/stdc++.h>
using namespace std;

int bubble_sort(int arr[], int n){
	int swapped=0;
	for(int i=0;i<n-1;i++){
		swapped=0;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int k=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=k;
				swapped=1;
			}
		}
		if(swapped==0)
			break;
	}
}
main(){
	int n;
	cin>>n;
	int arr[10000];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}