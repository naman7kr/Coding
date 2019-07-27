#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<int,int> dfs(std::vector<pair<int,int>> v[],int n,int src){
    stack<int> s;
    s.push(src);
    int vis[n+10]={0};
    int dist[n+10];
    for(int i=0;i<n+10;i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    while(!s.empty()){
        int p = s.top();
        s.pop();
        for(int i=0;i<v[p].size();i++){
            if(!vis[v[p][i].first] && dist[v[p][i].first]>dist[p]+v[p][i].second){
                dist[v[p][i].first]=dist[p]+v[p][i].second;
                vis[v[p][i].first] = 1;
                s.push(v[p][i].first);
            }
        }
    }
    int mx = -1;
    pair<int,int> pr;
    for(int i=1;i<=n;i++){
        if(mx <dist[i]){
            mx = dist[i];
            pr = {i,mx};
        }
    }
    return pr;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<pair<int,int>> v[n+10];
        for(int i=0;i<n-1;i++){
            int a,b,d;
            cin>>a>>b>>d;
            v[a].emplace_back(make_pair(b,d));
            v[b].emplace_back(make_pair(a,d));
        }
        int d1 = dfs(v,n,1).first;
        
        int mx = dfs(v,n,d1).second;

        if(mx<100){
            cout<<0<<" "<<mx<<"\n";
        }else if(mx<=1000)
            cout<<100<<" "<<mx<<"\n";
        else if(mx<=10000){
            cout<<1000<<" "<<mx<<"\n";
        }else{
            cout<<10000<<" "<<mx<<"\n";
        }
    }
}