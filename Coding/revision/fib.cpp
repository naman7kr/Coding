#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int fib_rec(int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	return fib_rec(n-1)+fib_rec(n-2);
}
std::vector<int> dp_r(MAX,-1);
int dp_rec(int n){
	dp_r[0] = 0;
	dp_r[1] = 1;
	if(n==0)
		return dp_r[0];
	if(n==1)
		return dp_r[1];
	if(dp_r[n]==-1){
		dp_r[n] = dp_rec(n-1)+dp_rec(n-2);
	}
	return dp_r[n];
}

int dp_iterative(int n){
	std::vector<int> dp_i(MAX);
	dp_i[0] = 0;
	dp_i[1] = 1;
	int i = 2;
	while(i<=n){
		dp_i[i++] = dp_i[i-1]+dp_i[i-2]; 
	}
	return dp_i[n];
}
int simple(int n){
	int a=0,b=1,c,i=1;
	if(n==0)
		return a;
	if(n==1)
		return b;
	while(i<n){
		c = a+b;
		a = b;
		b = c;
		i++;

	}
	return c;
}
int multiply(int A[2][2], int B[2][2]){
	int a = A[0][0]*B[0][0]+A[0][1]*B[1][0];
	int b = A[0][0]*B[0][1]+A[0][1]*B[1][1];
	int c = A[1][0]*B[0][0]+A[1][1]*B[1][0];
	int d = A[1][0]*B[0][1]+A[1][1]*B[1][1];
	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}
int power(int M[2][2],int n){
	int res[2][2]={{1,1},{1,0}};
	while(n>0){
		if(n&1){
			multiply(res,M);
		}
		n = n>>1;
		if(n==0)break;
		multiply(M,M);
	}
	return res[0][0];
}
int fib_pow(int n){
	//(O(log(n)))
	int M[2][2] = {{1,1},{1,0}};
	if(n==0 || n==1)
		return M[1][(n+1)%2];

	return power(M,n-2);
}

int formula(int n){
	double phi = (1+sqrt(5))/2;
	return round((pow(phi,n)/(sqrt(5))));
}
double pow(double a,int n){
	int res = 1;
	while(n>0){
		if(n&1)
			res = res * a;
		n=n>>1;
		a = a*a;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	cout<<"Recursive:"<<fib_rec(n-1)<<"\n";
	cout<<"DP Recursive:"<<dp_rec(n-1)<<"\n";
	cout<<"DP Iterative:"<<dp_iterative(n-1)<<"\n";
	cout<<"Simple:"<<simple(n-1)<<"\n";
	cout<<"Fib Pow:"<<fib_pow(n-1)<<"\n";
	cout<<"formula:"<<formula(n-1)<<"\n";
	return 0;
}