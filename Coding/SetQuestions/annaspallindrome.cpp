#include <bits/stdc++.h>
using namespace std;


main(){
	string s;
	cin>>s;
	int len = s.length();
	int cnt=0;

	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
			cnt++;
	}
	
	if(len&1 && cnt==0){
		cout<<"YES";
		return 0;
	}

	if(cnt==1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}