#include <bits/stdc++.h>
using namespace std;
class RMQ{

	public:
		int n;
		RMQ(vector<int> v){
			n = v.size();
			log_table.assign(n+1,0);
			for(int i=2;i<log_table.size();i++){
				log_table[i] = log_table[i/2] + 1;
			}
			sparse_table.assign(log_table.back()+1,vector<int>(v.size()));
			sparse_table[0] = v;
			for(int row=1;row<sparse_table.size();row++){
				for(int i = 0;i+(1<<row)<=n;i++){
					sparse_table[row][i] = min(sparse_table[row-1][i],sparse_table[row-1][i+(1<<(row-1))]);
				}
			}
		}
		int getMinimum(int l, int r){
			int k = log_table[r-l+1];
			return min(sparse_table[k][l],sparse_table[k][r-(1<<k)+1]);
		}
	private:
		vector<int> log_table;
		vector<vector<int>> sparse_table;
};
vector<vector<int>> adj;
vector<int> euler_tour;
vector<int > new_to_old;
vector<int> first_endcounter;
void dfs_euler_tour(int v, int p){
	int new_index = new_to_old.size();
	new_to_old.push_back(v);
	first_endcounter[v] = euler_tour.size();
	euler_tour.push_back(new_index);

	for(auto u:adj[v]){
		if(u!=p){
			dfs_euler_tour(u,v);
			euler_tour.push_back(new_index);
		}
	}
}
main(){
	int nodes = 10;
	vector<pair<int, int>> edges = {{0, 5},{7, 2}, {5, 1},{1, 3},{1, 6}, {5,8}, {0,9}, {9,4}};
	adj.resize(nodes);
	for(auto edge: edges){
		adj[edge.first].emplace_back(edge.second);
		adj[edge.second].emplace_back(edge.first);
	}
	first_endcounter.resize(nodes);
	dfs_euler_tour(0,-1);
	int u,v;
	cin>>u>>v;

	int f1 = first_endcounter[u];
	int f2 = first_endcounter[v];
	if(f1>f2)
		swap(f1,f2);
	RMQ q(euler_tour);
	int ans = q.getMinimum(f1,f2);
	cout<<new_to_old[ans]<<"\n";
}


