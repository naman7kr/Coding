#include <stdio.h>


void getResults(int ar[], int bt[], int wt[], int tt[],int ct[], int n){
	int sum = bt[0];
	int i;
	wt[0] = 0;
	tt[0] = bt[0];
	ct[0] = tt[0]+ar[0];
	for(i = 1; i< n; i++){
		wt[i] = sum - ar[i];
		tt[i] = wt[i] + bt[i];
		ct[i] = tt[i] + ar[i];
		sum+= bt[i];
	}
}
void printResults(int wt[], int tt[], int ct[], int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d %d %d\n", wt[i],tt[i], ct[i]);
	}
}
int main(){
	int n,wt[100],ar[100],bt[100],tt[100],ct[100];
	scanf("%d",&n);
	int i;
	for(i = 0; i<n ; i++)
		scanf("%d %d",ar+i,bt+i);
	getResults(ar,bt,wt,tt,ct,n);
	printResults(wt,tt,ct, n);
}