#include <bits/stdc++.h>
using namespace std;

#define pr pair<int,int>
#define vp vector<pr > 

// int dist[100000];
// int parent[100000];
// int visited[100000]={0};
// void dijkstra(vp v[], int src, int V, int E){
	
// 	for(int i=0;i<V;i++){
// 		dist[i]=INT_MAX;
// 		parent[i]=-1;
// 	}
// 	multiset<pr > s;
// 	s.insert({0,src});
// 	dist[src]=0;
// 	while(!s.empty()){
// 		pr p=*s.begin();

// 		s.erase(s.begin());
// 		if(visited[p.second]) continue;
// 		visited[p.second]=1;
// 		for(int i=0;i<v[p.second].size();i++){
// 			if(dist[p.second]!=INT_MAX && dist[v[p.second][i].second]>dist[p.second]+v[p.second][i].first){
// 				dist[v[p.second][i].second]=dist[p.second]+v[p.second][i].first;
// 				s.emplace(make_pair(dist[v[p.second][i].second],v[p.second][i].second));
// 				parent[v[p.second][i].second]=p.second;
// 			}
// 		}
// 	}
// }
vector<vector<pr>> adj;
vector<int> dist;
vector<int> parent;
void dijkstra(int src,int V){
	dist.assign(V,INT_MAX);
	parent.assign(V,-1);
	queue<int> q;
	q.push(src);	
	dist[src] = 0;
	while(!q.empty()){
		
		int v = q.front();
		q.pop();
	
		for(auto u: adj[v]){
			if(dist[v]!=INT_MAX && dist[u.second]>dist[v]+u.first){
				dist[u.second] = dist[v]+u.first;
				parent[u.second] = v;
				q.emplace(u.second);
			}
		}
	}
}
void getPathToDest(int dest){
	if(parent[dest]==-1){
		cout<<dest;
		return;
	}
	getPathToDest(parent[dest]);
	cout<<"->"<<dest;
}
main(){
	int V,E;
	cin>>V>>E;
	// vp v[V];
	adj.resize(V);
	for(int i=0;i<E;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		adj[src].push_back({weight,dest});
		adj[dest].push_back({weight,src});
		// v[src].push_back(make_pair(weight,dest));
		// v[dest].push_back(make_pair(weight,src));
	}

	int srcV;
	cin>>srcV;
	dijkstra(srcV,V);
	//dijkstra(v,srcV,V,E);
	int vertex;
	
		cin>>vertex;
		
		int cost=dist[vertex];
		getPathToDest(vertex);
		cout<<"\n"<<"cost:"<<cost;
}