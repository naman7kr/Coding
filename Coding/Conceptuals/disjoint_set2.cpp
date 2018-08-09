//includes rank and path compression
//checking if graph is cyclic or not

#include <bits/stdc++.h>
#define vp std::vector<pair<int,int> >
using namespace std;

int find(int parent[], int i){
	if(parent[i]==-1){
		return i;
	}
	parent[i]=find(parent,parent[i]);
	return parent[i];
}

void Union(int parent[],int rank[], int x, int y){
	int setx=find(parent,x);
	int sety=find(parent,y);
	
	if(rank[setx]>=rank[sety]){
		rank[setx]=(rank[setx]==rank[sety]?rank[setx]+1:rank[setx]);
		parent[sety]=setx;
	}else{
		parent[setx]=sety;
	}
}


bool checkCyclic(vp &v,int E, int V){
	int *parent=(int*)malloc(sizeof(int)*v.size());
	int *rank=(int*)malloc(sizeof(int)*v.size());
	
	memset(parent,-1,sizeof(int)*v.size());
	memset(rank,0,sizeof(int)*V);

	for(int i=0;i<E;i++){
		int x=find(parent,v[i].first);
		int y=find(parent,v[i].second);
		if(x==y){
			return true;
		}
		Union(parent,rank,x,y);
	}
}


main(){
	int V;
	int E;
	cin>>V>>E;
	 vp v;
	for(int i=0;i<E;i++){
		int src,dest;
		cin>>src>>dest;
		v.push_back(make_pair(src,dest));
	}

	if(checkCyclic(v,E,V)){
		cout<<"Its cyclic"<<"\n";
	}else{
		cout<<"Not cyclic\n";
	}
}