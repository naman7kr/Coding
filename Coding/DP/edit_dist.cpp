#include <bits/stdc++.h>
using namespace std;


main(){
	string s1,s2;
	cin>>s1>>s2;

	//s1->s2
	// delete->(n-1,m),update->(n-1,m-1),insert->(n,m-1)
	int n=s1.length();
	int m=s2.length();
	int ed[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)
				ed[i][j]=j;
			else if(j==0)
				ed[i][j]=i;
			else if(s1[i-1]==s2[j-1]){
				ed[i][j]=ed[i-1][j-1];
			}else{
				ed[i][j]=1+min(min(ed[i-1][j],ed[i][j-1]),ed[i-1][j-1]);
			}
		}
	}
	cout<<ed[n][m];
}