#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

std::vector<int> factor(MAX);

void getSmallestFactor(){
	factor[0]=0;
	for(int i=1;i<MAX;i++)
		factor[i]=i;
	for(int i=2;i<MAX;i+=2)
		factor[i]=2;

	for(int i=3;i*i<MAX;i+=2){
		for(int j=i*i;j<MAX;j+=i){
			if(factor[j]==j){
				factor[j]=i;
			}
		}
	}
}

int calculate_no_factors(int n){
	int ans = 1;
	if(n==1)
		return 1;
	//get smallest factor 
	int dup=factor[n];
	int p = n/dup;
	int c=1;
	while(p!=1){
		if(factor[p]==dup){
			c++;
		}else{
			dup = factor[p];
			ans = ans*(c+1);
			c=1;
		}
		p=p/dup;
	}
	ans = ans*(c+1);
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	
	getSmallestFactor();

	printf("%d\n",calculate_no_factors(n));
	return 0;
}