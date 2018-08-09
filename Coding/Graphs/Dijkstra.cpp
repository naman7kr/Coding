#include <bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define vp vector<pr > 

int dist[100000];
int parent[100000];
int visited[100000]={0};
void dijkstra(vp v[], int src, int V, int E){
	
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	multiset<pr > s;
	s.insert({0,src});
	dist[src]=0;
	while(!s.empty()){
		pr p=*s.begin();

		s.erase(s.begin());
		if(visited[p.second]) continue;
		visited[p.second]=1;
		for(int i=0;i<v[p.second].size();i++){
			if(dist[p.second]!=INT_MAX && dist[v[p.second][i].second]>dist[p.second]+v[p.second][i].first){
				dist[v[p.second][i].second]=dist[p.second]+v[p.second][i].first;
				s.emplace(make_pair(dist[v[p.second][i].second],v[p.second][i].second));
				parent[v[p.second][i].second]=p.second;
			}
		}
	}
}

main(){
	int V,E;
	cin>>V>>E;
	vp v[V];
	for(int i=0;i<E;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		v[src].push_back(make_pair(weight,dest));
		v[dest].push_back(make_pair(weight,src));
	}
	int srcV;
	cin>>srcV;
	dijkstra(v,srcV,V,E);
	int vertex;
		cout<<"Enter the vertex to trace from 0 :";
		cin>>vertex;
		int cost=dist[vertex];
		while(vertex!=-1){
			cout<<vertex<<"<-";
			vertex=parent[vertex];
		}

		cout<<"\n"<<"cost:"<<cost;
}