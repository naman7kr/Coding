#include <bits/stdc++.h>
using namespace std;
#define vp std::vector< pair <int,int> >

int find(int parent[], int i){
	if(parent[i]==-1){
		return i;
	}
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){
	int setx=find(parent,x);
	int sety=find(parent,y);
	parent[setx]=sety;
}



bool checkCyclic(vp &v,int E, int V){
	if(E<3){
		return false;
	}
	int *parent=(int*)malloc(sizeof(int)*v.size());
	memset(parent,-1,sizeof(int)*v.size());
	for(int i=0;i<E;i++){
		int x=find(parent,v[i].first);
		int y=find(parent,v[i].second);
		if(x==y){
			return true;
		}
		Union(parent,x,y);
	}
}

main(){
	int V;
	cin>>V;
	int E;
	cin>>E;
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