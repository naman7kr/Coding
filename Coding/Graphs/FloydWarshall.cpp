#include <bits/stdc++.h>
using namespace std;
int V,E;
int adj[1000][1000];
int dist[1000][1000];
void floydWarshall(){
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			if(i==j)
				dist[i][j]=0;
			else if(adj[i][j]){
				dist[i][j]=adj[i][j];
			}
			else{
				dist[i][j]=INT_MAX;
			}
		}
	}
	
	for(int k=1;k<=V;k++){
		for(int j=1;j<=V;j++){
			for(int i=1;i<=V;i++){
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int flag=1;
	
	for(int i=1;i<=V;i++){
		if(dist[i][i]<0){
			cout<<"Negative Cycle";
			flag=0;
			break;
		}
	}
	if(flag)
	for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>V>>E;
	
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			cin>>adj[i][j];

	floydWarshall();
}