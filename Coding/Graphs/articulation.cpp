#include <bits/stdc++.h>
using namespace std;

main(){
	set<int> s;
	s.emplace(1);
	s.emplace(3);
	set<int>::iterator it=s.end();
	it--;
	cout<<*(--it);
}