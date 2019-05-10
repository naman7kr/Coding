#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         if(n==1){
            cout<<a[0]<<"\n";
            continue;
        }
        sort(a,a+n);
        
        for(int i=0;i<n-1;i++){
            if(a[i]>k){
                int d = a[i] - k;
                a[i] = a[i] - d;
               // cout<<a[i]<<" ";
                a[i+1] = a[i+1]-d;
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            //cout<<a[i]<<" ";
            ans+=a[i];
        }
        cout<<ans<<"\n";
    }
}