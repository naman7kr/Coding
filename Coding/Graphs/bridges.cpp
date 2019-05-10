#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;
vector<int> bridge;
vector<int> visited;
vector<int> low;
vector<int> ids;
int id =0;
void dfs(int src, int parent, vector<int> &bridge){
	id+=1;
	low[src] = ids[src] = id;
	visited[src]=1;
	
	for(auto u: adj[src]){

		if(u==parent)
			continue;
		if(!visited[u]){
			dfs(u,src,bridge);
			low[src] = min(low[src], low[u]);
			if(	ids[src]<low[u]){
				bridge.push_back(src);
				bridge.push_back(u);
			}

		}else{
			low[src] = min(low[src], ids[u]);
		}
	} 
}
int main(){
	int V,E;
	cin>>V>>E;
	
	adj.resize(V);
	low.resize(V);
	ids.resize(V);
	for(int i=0;i<E;i++){
		int src,dest;
		cin>>src>>dest;
		adj[src].emplace_back(dest);

	}

	visited.assign(V,0);
	for(int i=0;i<V;i++){
		if(!visited[i])
			dfs(i,-1,bridge);

	}
	for(int i=0;i<bridge.size();i+=2)
		cout<<bridge[i]<<"->"<<bridge[i+1]<<"\n";
return 0;
}
// 9 10
// 0 1 
// 1 2
// 2 0
// 2 3
// 3 4
// 2 5
// 5 6
// 6 7
// 7 8
// 8 5