#include <bits/stdc++.h>
using namespace std;
#define vp std::vector< std::vector<int> > 

void bfs(vp v, int V, int src){
	queue<int> q;
	q.push(src);
	int visited[V+10]={0};
	visited[src]=1;
	cout<<src<<" ";
	while(!q.empty()){
		int p=q.front();
		q.pop();
		
		for(int i=0;i<v[p].size();i++){
			if(visited[v[p][i]]==0){
				q.push(v[p][i]);
				visited[v[p][i]]=1;
				cout<<v[p][i]<<" ";
			}
		}
	}
}

main(){
	int V;
	int E;
	cin>>V>>E;
	 vp v(V);
	 for(int i=0;i<E;i++){
	 	int src,dest;
		cin>>src>>dest;
		v[src].emplace_back(dest);
		v[dest].emplace_back(src);
	 }
	
	 bfs(v,V,1);
}