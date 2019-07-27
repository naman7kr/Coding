#include <bits/stdc++.h>
using namespace std;
#define vp std::vector< std::vector<pair<int,int> > > 


int dist[10000]={INT_MAX};

void bfs(vp v, int V, int src){
	deque<int> q;
	for(int i=0;i<V+10;i++){
		dist[i]=INT_MAX;
	}
	q.push_front(src);
	dist[src]=0;
	while(!q.empty()){
		int p=q.front();
		q.pop_front();
		for(int i=0;i<v[p].size();i++){
		//for(auto u: v[p])	
			if(dist[v[p][i].first]>v[p][i].second+dist[p]){
				dist[v[p][i].first]=v[p][i].second+dist[p];
				
				if(v[p][i].second==0){
					q.push_front(v[p][i].first);
				}else{
					q.push_back(v[p][i].first);
				}
			}
		}
	}
}

main(){
	int V;
	int E;
	cin>>V>>E;
	 vp v(V,vector<pair<int, int>>(V-1,{0,0}));
	 for(int i=0;i<E;i++){
	 	int src,dest,weight;
		cin>>src>>dest>>weight;
		v[src].emplace_back(make_pair(dest,weight));
		v[dest].emplace_back(make_pair(src,weight));
	 }
	 int src,query;
	 cin>>src>>query;
	 bfs(v,V,src);
	 cout<<dist[query];
}