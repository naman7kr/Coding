#include <bits/stdc++.h>
using namespace std;
#define vp std::vector<pair<int, int> >

// int dist[10000];
// int parent[10000];
// int bellmanford(vp v[],int src,int V,int E){
	
	
// 	for(int i=0;i<V;i++){
// 		dist[i]=INT_MAX;
// 		parent[i]=-1;
// 	}
	
// 	int cnt=V-1;
// 	dist[src]=0;
// 	int flag=1;

// 	while(cnt--){
// 		for(int i=0;i<V;i++){
// 			for(int j=0;j<v[i].size();j++){

// 				if(dist[i]!=INT_MAX && dist[v[i][j].second]>dist[i]+v[i][j].first){
// 					dist[v[i][j].second]=dist[i]+v[i][j].first;
// 					parent[v[i][j].second]=i;	
// 				}
// 			}		
// 		}
// 	}
// 	for(int i=0;i<V;i++){
// 		for(int j=0;j<v[i].size();j++){
// 			if(dist[v[i][j].second]>dist[i]+v[i][j].first){
// 				flag=0;
// 				break;
// 			}
// 		}
// 		if(flag==0){
// 			break;
// 		}
// 	}
// 	if(flag==0){
// 		cout<<"Negative Cycle is present\n";
// 		return 0;
// 	}else{
// 		return 1;
// 	}
// }
vector<pair<int,pair<int, int >>> adj;
vector<int> parent;
vector<int> dist;
int bellmanford(int src,int V,int E){
	int limit = V-1;
	parent.assign(V,-1);
	dist.assign(V,INT_MAX);
	dist[src] = 0;
	while(limit--){
		for(auto edge:adj){
			int s = edge.second.first;
			int d = edge.second.second;
			int w = edge.first;
			if(dist[s]!=INT_MAX && dist[d] > dist[s] + w){
				dist[d] = dist[s] + w;
				parent[d] = s;

			}
		}
	}
	for(auto edge:adj){
		int s = edge.second.first;
		int d = edge.second.second;
		int w = edge.first;
		if(dist[d]>dist[s]+w){
			return 0;
		}
	}
	return 1;
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
	adj.resize(2*E);
	for(int i=0;i<E;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj.push_back({w,{u,v}});
		adj.push_back({w,{v,u}});
	}

	int src,dest;
	cin>>src>>dest;
	if(bellmanford(src,V,E)){
		cout<<"\n";
		getPathToDest(dest);
		cout<<"\n"<<dist[dest];
		return 1;
	}else{
		cout<<"Negative cycle exists";
		return 1;
	}
	
	// vp v[V+10];
	// for(int i=0;i<E;i++){
	// 	int src,dest,weight;
	// 	cin>>src>>dest>>weight;
	// 	v[src].push_back(make_pair(weight,dest));
	// }
	// if(bellmanford(v,0,V,E)){
	// 	int vertex;
	// 	cout<<"Enter the vertex to trace from 0 :";
	// 	cin>>vertex;
	// 	int cost=dist[vertex];
	// 	while(vertex!=-1){
	// 		cout<<vertex<<"<-";
	// 		vertex=parent[vertex];
	// 	}

	// 	cout<<"\n"<<"cost:"<<cost;
	// }

}