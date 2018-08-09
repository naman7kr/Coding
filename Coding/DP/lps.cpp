#include <bits/stdc++.h>
using namespace std;


main(){
	char ch[10000];
	cin>>ch;
	int lps[100][100];
	int n=strlen(ch);
	for(int i=0;i<n;i++)
		lps[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int i=0;i<n-len+1;i++){
			int j=i+len-1;
			if(ch[i]==ch[j]&&len==2)
				lps[i][j]=2;
			else if(ch[i]==ch[j])
				lps[i][j]=lps[i-1][j-1]+2;
			else 
				lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
		}
	}
	cout<<lps[0][n-1];
}