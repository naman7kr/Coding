#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100005

std::vector<bool> isPrime(MAX_SIZE,true);
std::vector<int> prime;
std::vector<int> spf(MAX_SIZE);

bool brute_force(int n){
	bool isPrime = true;
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			isPrime=false;
			break;
		}
	}

	if(isPrime){
		printf("%d is Prime\n", n);
	}else{
		printf("%d is not Prime\n",n);
	}
}
bool root_n_optimized(int n){
	bool isPrime = true;
	if(n<=1)
		isPrime = false;
	if(n<=3)
		isPrime = true;

	if(n%2==0 || n%3 == 0)
		isPrime = false;
	
	if(isPrime){
		for(int i=5;i*i<=n;i+=6){
			if(n%i==0 || n%(i+2)==0){
				isPrime = false;
				break;
			}
		}
	}
	if(isPrime){
		printf("%d is Prime\n", n);
	}else{
		printf("%d is not Prime\n",n);
	}
}
void seive_of_eratosthenes(int n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(prime[i]){
			cout<<i<<" ";
		}
	}
	cout<<"\n";
}
void seive_manipulated(int n){
	//O(n) method
	isPrime[0]=false;
	isPrime[1]=false;
	for(int i=2;i<=n;i++){
		if(isPrime[i]){
			prime.push_back(i);
			spf[i]=i;
		}
		for(int j=0;j<prime.size() 
			&& i*prime[j]<=n 
			&& prime[j]<=spf[i];j++)
		{
			isPrime[i*prime[j]]=false;
			spf[i*prime[j]]=prime[j];
		}
	}
	
	for(int i=0;i<prime.size();i++)
		printf("%d ", prime[i]);
	printf("\n");
}
int main(){
	//check if a number is a prime number
	int n;
	cin>>n;
	//This is a real brute-force method
	brute_force(n);
	
	//root n optimised method
	root_n_optimized(n);

	//seive of Eratonthenes
	seive_of_eratosthenes(n);

	//O(n) seive 
	seive_manipulated(n);
}