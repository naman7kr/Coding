#include <bits/stdc++.h>
#define MAX (int)1e5
using namespace std;

int ceilElem(int a[],int* inc_sub,int val, int len){
	int l=0,r=len;
	int ans=-1;
	while(l<=r){
		int mid=((l+r)/2);
		if(a[inc_sub[mid]]==val){
			ans=mid;
			l=mid+1;
		}else if(a[inc_sub[mid]]>val){
			r=mid-1;
		}else
			l=mid+1;
	}
	return ans;
}
int getlis(int* inc_sub,int* parent,int a[],int n){
	int len=1;
	inc_sub[0]=a[0];
	for(int i=1;i<n;i++){
		if(a[inc_sub[0]]>a[i])
			inc_sub[0]=i;
		else if(a[inc_sub[len-1]]<a[i]){
			inc_sub[len]=i;
			len++;
		}else{
			int pos=ceilElem(a,inc_sub,a[i],len-1);
			inc_sub[pos]=i;
		}

	}
	return len;
}

main(){
	int n;
	cin>>n;
	int a[MAX];
	for(int i=0;i<n;i++)cin>>a[i];
	int *lis=new int[MAX];
	int *inc_sub=new int[MAX+1];
	int *parent=new int[MAX];
	cout<<getlis(inc_sub,parent,a,n)<<"\n";
}