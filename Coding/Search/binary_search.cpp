#include <bits/stdc++.h>
using namespace std;

int binary_search_not_using_rec(std::vector<int> v,int s,int n);
int binary_search_using_rec(std::vector<int> v,int s,int l,int h);

main(){
	int n;
	cin>>n;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		int vi;
		cin>>vi;
		v.push_back(vi);
	}
	int s;
	cin>>s;

	sort(v.begin(),v.end());

	// if(binary_search_using_rec(v,s,0,n-1)!=-1){
	// 	cout<<"Found "<<"\n";
	// }else {
	// 	cout<<"Not Found"<<"\n";
	// }
	if(binary_search_not_using_rec(v,s,n)){
		cout<<"Found "<<"\n";
	}else {
		cout<<"Not Found"<<"\n";
	}
}
int binary_search_using_rec(std::vector<int> v,int s,int l,int h){
	
	if(l<=h){
		int mid=(l+h)/2;
		if(v[mid]==s){
			return 1;
		}else if(v[mid]>s){
			 return binary_search_using_rec(v,s,l,mid-1);
		}else{
			 return binary_search_using_rec(v,s,mid+1,h);
		}
	}
	return -1;
}
int binary_search_not_using_rec(std::vector<int> v,int s,int n){
	int l=0;
	int h=n-1;
	int flag=0;
	while(l<=h){

		int mid = (l+h)/2;
		if(v[mid]==s){
			flag=1;
			break;
		}else if(v[mid]<s){
			l=mid+1;
		}else{
			h=mid-1;
		}
	}
	if(flag==0){
		return 0;
	}
	else{
		return 1;
	}
}