#include<bits/stdc++.h>
using namespace std;
//long long T,n,h,m,b,x,y,t,k,a,sum,sum1;
long long x,y,n;
long long dp[1000000][3],A[100000],cost[100000];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>A[i];
	
	for(int i=0;i<n;i++)
	cin>>cost[i],dp[i][1]=cost[i],dp[i][2]=1e18,dp[i][3]=1e18;
	
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(A[i]<A[j])
	{
		dp[j][2]=min(dp[j][2],dp[i][1]+cost[j]);
		dp[j][3]=min(dp[j][3],dp[i][2]+cost[j]);
	}
	
	long long ans=1e18;
	for(int i=0;i<n;i++)
	ans=min(ans,dp[i][3]);
	
	if(ans==1e18)ans=-1;
	cout<<ans<<endl;
}