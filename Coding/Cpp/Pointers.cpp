#include <bits/stdc++.h>
using namespace std;
void swap (int& a, int& b){
	a=a^b;
	b=a^b;
	a=a^b;
}

main(){
	int a,b;
	cin>>a>>b;
	swap(a,b);
	cout<<a<<" "<<b;
}