#include <bits/stdc++.h>
using namespace std;

int main(){	
	int n,m;
	cin>>n>>m;
	int s[100000];
	for(int i=1;i<=m;i++)cin>>s[i];
	int dp[n+10]={0};
	dp[0]=1;
	for(int i=0;i<m;i++){
		for(int j=s[i];j<=n;j++){
				dp[j]+=dp[j-s[i]];
		}
	}
	cout<<dp[n];


}