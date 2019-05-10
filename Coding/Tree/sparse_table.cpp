
//RMQ
#include <bits/stdc++.h>
using namespace std;
int n;
class RMQ{
	public:
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
		int query(int l, int r){
			int k = log_table[r-l+1];
			return min(sparse_table[k][l],sparse_table[k][r-(1<<k)+1]);
		}
	private:
		vector<int> log_table;
		vector<vector<int>> sparse_table;
};
int main(){
	std::vector<int> v{5,2,4,7,6,3,1,2};
	RMQ sp(v);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<sp.query(l,r)<<"\n";
	}
	// cin>>n;
	// vector<int> a;
	// int sparse_table[1000][1000]={0};
	// for(int i=0;i<n;i++){
	// 	int ai;
	// 	cin>>ai;
	// 	a.push_back(ai);		
		
	// }
	// //initialize sparse matrix
	
	// for(int i = 0;i<n;i++){
	// 	sparse_table[i][0]=i;
	// }
	// for(int j=1;(1<<j)<n;j++){
	// 	for(int i = 0;i+(1<<j)<=n;i++){
	// 	//	cout<<a[sparse_table[i][j-1]]<<" "<<a[sparse_table[i+(1<<(j-1))][j-1]]<<"\n";
	// 		if(a[sparse_table[i][j-1]]<a[sparse_table[i+(1<<(j-1))][j-1]])
	// 			sparse_table[i][j]=sparse_table[i][j-1];
	// 		else
	// 			sparse_table[i][j]=sparse_table[i+(1<<(j-1))][j-1];
	// 	}
	// }
	// for(int j=0;(1<<j)-1<n;j++){
	// 	for(int i = 0;i+(1<<j)<=n;i++){
	// 		cout<<sparse_table[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// int q;
	// cin>>q;
	// while(q--){
	// 	int l,r;
	// 	cin>>l>>r;
	// 	int k = (int)log2(r-l+1);
	// 	//RMQ
	// 	cout<<min(a[sparse_table[l][k]],a[sparse_table[r-(1<<k)+1]

	// 		[k]])<<"\n";

	// }
}

