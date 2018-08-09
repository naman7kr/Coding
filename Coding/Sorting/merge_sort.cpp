#include <iostream>
using namespace std;

void merge(int [],int,int);
void merge_sort(int [],int ,int ,int );
main(){
	int n;
	cin>>n;
	int arr[100000];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	merge(arr,0,n-1);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
void merge(int arr[],int s,int e){
	if(s<e){
		int mid=(s+e)/2;
		merge(arr,s,mid);
		merge(arr,mid+1,e);
		merge_sort(arr,s,mid,e);
	}
}
void merge_sort(int arr[],int s,int mid, int e){
	int b[100000];
	int st=s;
	int end=mid+1;

	int k=st;
	while(st<=mid && end<=e){
		if(arr[st]<arr[end]){
			b[k++]=arr[st++];
		}else{
			b[k++]=arr[end++];
		}
	}
	while(st<=mid){
		b[k++]=arr[st++];
	}
	while(end<=e){
		b[k++]=arr[end++];
	}
	for(int i=s;i<=e;i++){
		arr[i]=b[i];
	}
}