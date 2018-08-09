#include <bits/stdc++.h>
using namespace std;
int n;


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
   	unordered_map<string, vector<int> > m;
   	for(int i=0;i<n;i++){
   		string t;cin>>t;
   		unordered_map<string,std::vector<int>>::iterator it=m.find(t);
   		if(it==m.end()){
   			vector<int> v;
   			v.emplace_back(i+1);
   			m.insert({t,v});
   		}else{
   			it->second.emplace_back(i+1);
   		}
   	}
   	int tc;cin>>tc;
   	while(tc--){
   		int l,r;cin>>l>>r;
   		string temp;
   		unordered_map<string,std::vector<int> >:: iterator it=m.find(temp);
   		if(it==m.end()){
   			cout<<0<<"\n";
   			continue;
   		}
   		std::vector<int> v(it->second);
   		int low = lower_bound(v.begin(),v.end(),l)-v.begin();
   		int up = upper_bound(v.begin(),v.end(),r-1)-v.begin();
   		cout<<up-low<<"\n;
   	}
}