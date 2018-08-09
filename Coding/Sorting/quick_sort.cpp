#include <bits/stdc++.h>
using namespace std;

void print(std::vector<int> v);
class Partition{
	
public:
	static int partitionStart(std::vector<int> &v,int low,int high){
		int fpivot=0;
		for(int i=low+1;i<=high;i++){
			if(v[low]>v[i]){
				fpivot++;
				iter_swap(v.begin()+i,v.begin()+fpivot+low);
			}

		}
		iter_swap(v.begin()+low,v.begin()+fpivot+low);
		return (low+fpivot);
	}
	static int partitionEnd(std::vector<int> &v,int low,int high){
		int fpivot=-1;

		for(int i=low;i<=high-1;i++){
			if(v[high]>v[i]){
				fpivot++;
				iter_swap(v.begin()+i,v.begin()+fpivot+low);
			}
		}
		iter_swap(v.begin()+high,v.begin()+fpivot+1+low);
		return (low+fpivot+1);
	}
	static int partitionMid(std::vector<int> &v,int low,int high){
		// int mid=(low+high)/2;
		// iter_swap(v.begin()+mid,v.begin());
		// return partitionStart(v,low,high);
		int mid=(low+high)/2;
		int i=low;
		int j=high;
		int pivot=v[mid];
		cout<<"LOW"<<low<<"HIGH"<<high<<"\n";
		while(i<=j){
			print(v);
			while(v[i]<pivot){
				i++;	
			}
			while(v[j]>pivot){
				j--;
			}
			
			if(i<=j){
				iter_swap(v.begin()+i,v.begin()+j);
				i++;
				j--;
			}
		}
		print(v);
		cout<<i<<"\n";
		return i-1;
	}
	static int partitionRandom(std::vector<int> &v,int low,int high){

	} 
};
void quick_sort_mid(std::vector<int> &v,int low, int high){
	int mid=(low+high)/2;
		int i=low;
		int j=high;
		int pivot=v[mid];
		while(i<=j){
			while(v[i]<pivot){
				i++;	
			}
			while(v[j]>pivot){
				j--;
			}
			
			if(i<=j){
				iter_swap(v.begin()+i,v.begin()+j);
				i++;
				j--;
			}
		}
		if(low<j){
			quick_sort_mid(v,low,j);
		}
		if(i<high){
			quick_sort_mid(v,i,high);
		}
}
void quick_sort(std::vector<int> &v,int low, int high){
	if(low<high){
		int p=Partition::partitionMid(v,low,high);
		quick_sort(v,low,p-1);
		quick_sort(v,p+1,high);
	}
}

void print(std::vector<int> v){
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";
}


main(){
	int n;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		int vi;
		cin>>vi;
		v.push_back(vi);
	}
	quick_sort_mid(v,0,n-1);
	print(v);
}