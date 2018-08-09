#include <bits/stdc++.h>
using namespace std;
#define PP pair<int,int>
#define vp std::vector<PP>
int visited[100000]={0};
vp v[100000];
int prims(int src){
	priority_queue<PP,std::vector<PP>, greater <PP> > P;
	P.emplace(0,src);
	PP p;
	
	int minval=0;
	while(!P.empty()){
		
		p=P.top();		
		P.pop();
		if(visited[p.second]==1){
			continue;
		}
		visited[p.second]=1;
		minval+=p.first;
		for(int i=0;i<v[p.second].size();i++){
			if(visited[v[p.second][i].second]==0){
				P.push(v[p.second][i]);
			}
		}
	}
	return minval;

}

main(){
	int V,E;
	cin>>V>>E;
	
	for(int i=0;i<E;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		v[src].emplace_back(make_pair(weight,dest));
		v[dest].emplace_back(make_pair(weight,src));
	}	
	int minCost=prims(0);
	cout<<minCost;
}