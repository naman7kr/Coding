#include <bits/stdc++.h>
using namespace std;
#define vv std::vector<std::vector<int> > 

int visited[1000];
void init(int V){
	for(int i=0;i<V;i++){
		visited[i]=0;
	}
}
void dfsIterative(vv v,int V, int src){
	stack<int> stk;
	stk.push(src);
	visited[src]=1;
	cout<<src<<" ";
	while(!stk.empty()){
		int val=stk.top();
		
		stk.pop();
		for(int i=0;i<v[val].size();i++){
			if(!visited[v[val][i]]){
				visited[v[val][i]]=1;
				stk.push(v[val][i]);
				cout<<v[val][i]<<" ";
			}
		}
	}
}
void dfsRecursive(vv v, int V, int src){
	visited[src]=1;
	cout<<src<<" ";
	for(int i=0;i<v[src].size();i++){
		if(!visited[v[src][i]]){
			dfsRecursive(v,V,v[src][i]);
		}
	}
}

main(){
	int V,E;
	cin>>V>>E;
	vv v(V);
	for(int i=0;i<E;i++){
		int src;
		int dest;
		cin>>src>>dest;
		v[src].emplace_back(dest);
		v[dest].emplace_back(src);
	}
	
	int flag=1;
	int src;
	while(flag){
		cout<<"Enter the Case\n";
		int p;
		cin>>p;
		switch(p){
			case 1:
				init(V);
				cout<<"Input src: ";
				cin>>src;
				dfsIterative(v,V,src);
				cout<<"\n";
				break;
			case 2:
				init(V);
				cout<<"Input src: ";
				cin>>src;
				dfsRecursive(v,V,src);
				cout<<"\n";
				break;
			case 0:
				flag=0;
				break;
			default:
				cout<<"Wrong Input\n";
				break;
		
		}	
	}
}