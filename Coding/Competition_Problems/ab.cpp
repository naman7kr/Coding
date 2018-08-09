#include <bits/stdc++.h>
using namespace std;
#define mp map<string,std::set<pair<string, int> > >
#define mp1 map<string,std::vector<pair<string,int> > > 
main()
{
 int n;
 cin>>n;
 string s[n+10];
 mp m;
 mp1 m1;
 for(int i=1;i<=n;i++)cin>>s[i];
 for(int i=1;i<=n;i++){
     string t="";
     for(int j=0;j<s[i].length();j++){
        t=t+s[i][j];
        m[t].emplace(make_pair(s[i],i));  
        m1[t].push_back(make_pair(s[i],i));
       }
     }
 int q;
 cin>>q;
 while(q--){
    int r;
    string p;
    cin>>r>>p;
    string ans;

    string b;
    for(int i=p.size();i>0;i--){
         b=p.substr(0,i);
        if(m1.count(b)&&m1[b][0].second<=r){
           break;
        }
    } 
    auto it=m[b].begin();
    ans=it->first;
    while(it->second>r){
     it++;
     ans=it->first;
    
    }
    cout<<ans<<"\n";
 }
}