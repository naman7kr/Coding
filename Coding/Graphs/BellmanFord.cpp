#include <bits/stdc++.h>
using namespace std;
#define vp std::vector<pair<int, int> >

int dist[10000];
int parent[10000];
int bellmanford(vp v[],int src,int V,int E){
	
	
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	
	int cnt=V-1;
	dist[src]=0;
	int flag=1;

	while(cnt--){
		for(int i=0;i<V;i++){
			for(int j=0;j<v[i].size();j++){

				if(dist[i]!=INT_MAX && dist[v[i][j].second]>dist[i]+v[i][j].first){
					dist[v[i][j].second]=dist[i]+v[i][j].first;
					parent[v[i][j].second]=i;	
				}
			}		
		}
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<v[i].size();j++){
			if(dist[v[i][j].second]>dist[i]+v[i][j].first){
				flag=0;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}
	if(flag==0){
		cout<<"Negative Cycle is present\n";
		return 0;
	}else{
		return 1;
	}
}

main(){
	int V,E;
	cin>>V>>E;
	vp v[V+10];
	for(int i=0;i<E;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		v[src].push_back(make_pair(weight,dest));
	}
	if(bellmanford(v,0,V,E)){
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

}