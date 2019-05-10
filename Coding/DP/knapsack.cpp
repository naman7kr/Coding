#include <bits/stdc++.h>
using namespace std;
typedef struct item{
	int weight;
	int value;
	int pos;
}Item; 

bool compare(Item a, Item b){
	return (a.value/a.weight)>(b.value/b.weight);
}
double fractional_knapsack(Item item[],int n,int W){
	int w=0;
	double val=0.0;
	sort(item,item+n,compare);
	for(int i=0;i<n;i++){
		if(w+item[i].weight<=W){
			w+=item[i].weight;
			val+=item[i].value;
		}else{
			double left=W-w;
			val+=item[i].value*((double)left/item[i].weight);
			break;
		}
	}
	return val;

}
main(){
	int n;
	cin>>n;
	Item item[10000];
	for(int i=0;i<n;i++){
		int w,v;
		cin>>w>>v;
		item[i].weight=w;
		item[i].value=v;
		item[i].pos=i;
	}
	int W;
	cin>>W;	
	//cout<<fractional_knapsack(item,n,W);
	int k[100][100];
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0||w==0)k[i][w]=0;
			else if(item[i-1].weight<=w){
				k[i][w]=max(item[i-1].value+k[i-1][w-item[i-1].weight],k[i-1][w]);
			}else{
				k[i][w]=k[i-1][w];
			}
		}
	}
	cout<<k[n][W];
}