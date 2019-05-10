#include <bits/stdc++.h>
using namespace std;


main(){
	string s,t;
	cin>>s>>t;

	int lcs[s.length()+1][t.length()+1];
	for(int i=0;i<=s.length();i++){
		for(int j=0;j<=t.length();j++){
			if(i==0||j==0){
				lcs[i][j]=0;
			}
			else if(s[i-1]==t[j-1])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	int len=lcs[s.length()][t.length()];
	cout<<len<<"\n";
	char lcs_s[len+1];
	lcs_s[len]='\0';
	int i=s.length();
	int j=t.length();
	while(i>0&&j>0){
		if(s[i-1]==t[j-1]){
			lcs_s[len-1]=s[i-1];
			len--;
			i--;
			j--;
		}else if(lcs[i-1][j]>lcs[i][j-1])i--;
		else j--;
	}
	cout<<lcs_s;
}