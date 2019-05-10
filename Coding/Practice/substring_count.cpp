#include <bits/stdc++.h>
using namespace std;
int blk;
typedef struct Query{
	int l,r;
	string t;
	int pos;
}Query;
bool compare(Query q1,Query q2){
	if((q1.l)%blk!=(q2.l)%blk)
		return q1.l%blk<q2.l%blk;
	return q1.r<q2.r;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	blk=sqrt(n);
	string s[n+10];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int q;
	cin>>q;
	Query query[q+10];
	for(int i=0;i<q;i++){
		cin>>query[i].l>>query[i].r>>query[i].t;
		query[i].pos=i;
	}
	 sort(query,query+q,compare);
	int l,r;
	l=r=query[0].l;
	int ans[q+10]={0};
	int cnt=(s[l].find(query[0].t)!=string::npos)?1:0;
	cout<<cnt;
	for(int i=0;i<q;i++){
		while(l>query[i].l){
			l--;
			if(s[l].find(query[i].t)!=string::npos){
				cnt++;
			}
		}
		while(l<query[i].l){
			if(s[l].find(query[i].t)!=string::npos){
				cnt--;
			}
			l++;
		}
		while(r>query[i].r){
			if(s[r].find(query[i].t)!=string::npos)cnt--;
			r--;
		}
		while(r<query[i].r){
			r++;
			if(s[r].find(query[i].t)!=string::npos){
			    cnt++;
			}
		}
		ans[query[i].pos]=cnt;
	}
	for(int i=0;i<q;i++)	
		cout<<ans[i]<<"\n";
}