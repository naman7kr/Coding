#include <bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#define ll long long
#define MAX 100005 
using namespace std;

main(){
	
	int n,k;
	cin>>n;
	cin>>k;
	int a[MAX];
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	//create frequency array
	int f[MAX]={0};
	for(int i=0;i<n;i++){
		f[a[i]]=1;
	}
	ll ans=0;
	//check k-a[i] is present in frequency array
	for(int i=0;i<n;i++){
		if(k>=a[i] && f[k-a[i]]==1){
			ans++;
		}
	}
	//remove repeated pairs
	cout<<ans/2;
}
