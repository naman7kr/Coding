#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100000];
bool flag[100000]={false};
int vis[100000]={0};
int res=0;
int ans=0;
void solve(int len,int pos,int res){
	sort(a,a+n);
	for(int i=0;i+k<n;i++){
		int p=0;
		for (int j = 0; j < k; ++j)
		{
			int q;
			q=(p|a[i+j]);
			if(p!=q){
				ans++;
			}
			p=q;
		}
	}
}

main(){
	
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k>n){
		k=n;
	}
	solve(0,0,0);
	cout<<ans+n+1;
}