#include <bits/stdc++.h>
using namespace std;
 #define vp std::vector<pair<int,pair<int,int> > >
int parent[10000]={-1};
int rank[10000]={0};

int find(int a){
	if(parent[a]==-1){
		return a;
	}
	a=find(parent[a]);
	return a;
}
void Union(int sx,int sy){
	int x=find(sx);
	int y=find(sy);
	 if(rank[x]>=rank[y]){
	 	if(rank[x]==rank[y]){
	 		rank[x]++;
	 	}
	 	parent[y]=x;
	 }else{
	 	parent[x]=y;
	 }
}
void kruskal(vp v,int V, int E){
	sort(v.begin(),v.end());
	memset(parent,-1,sizeof(int)*V);
	for(int i=0;i<E;i++){
		int x=find(v[i].second.first);
		int y=find(v[i].second.second);
		if(x==y){}
		else{
			Union(x,y);
			cout<<v[i].second.first<<"->"<<v[i].second.second<<"\n";
		}	
	}
}

main(){
	int V,E;
	cin>>V>>E;
	vp v;
	for(int i=0;i<E;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		v.push_back(make_pair(weight, make_pair(src,dest)));
		
	}
	kruskal(v,V,E);
}
// 5 7
// 0 1 1
// 0 2 7
// 1 2 5
// 1 3 4
// 1 4 3
// 2 4 6
// 3 4 2