#include <bits/stdc++.h>
using namespace std;
  
void bs(long long l,long long u, long long val,long long a[],int n){

    while(l<=u){
        long long mid = (l+u)/2;
        long long part = 0;
        //cout<<mid<<" ";
        for(int i=0;i<n;i++){ 
            long long temp = mid;
            int flag=0;
            while(temp-a[i]>=0){
                temp = temp-a[i];
                i++;
                flag=1;
            }
            i--;
          //  cout<<temp<<"*";
            part++;
        }
      //   cout<<"\n"<<part<<" ";
       //  cout<<l<<" "<<u<<"\n";
        if(l==u)
        	break;
       
        if(part<=val){
            u = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<l<<"\n";
}
int main(){
int n,m;
cin>>n>>m;
long long a[100005];
long long sum=0,mx=0;
for(int i=0;i<n;i++){
    cin>>a[i];
}
  for(int i=0;i<n;i++){
  	sum+=a[i];
  	if(mx<a[i])
  		mx = a[i];
  }
 // cout<<mx<<"\n";
  bs(mx,sum,m,a,n);
}