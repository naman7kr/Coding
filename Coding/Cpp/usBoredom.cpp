//Boredom codeforces #260(div1)
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int f[100005];
 
int main()
{
   int n;
   cin>>n;
   map<int,int> m;
   vector<pair<int,int>> v;
   for(int i=0;i<n;i++){
    int a;
    cin>>a;
    m[a]++;
   }
   for(map<int,int>::iterator it=m.begin();it!=m.end();++it){
    v.emplace_back(make_pair(it->first,it->second));
   }
   for(int i=0;i<v.size();i++){
    int pr = i-1;
    while(pr>=0 && v[pr].first + 1 == v[i].first) pr--;
    if(pr<0){
        f[i] = 1LL*v[i].first*v[i].second;
    }else{
        f[i] = f[pr] + 1LL*v[i].first*v[i].second;
    }
    if(i!=0){
        f[i] = max(f[i],f[i-1]);
    }
   }
   cout<<f[(int)v.size()-1]<<"\n";
   return 0;
}