#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct sc{
    int sum;
    int id;
}Sc;
bool compare(Sc sc1, Sc sc2){
    if(sc1.sum==sc2.sum)return sc1.id<sc2.id;;
    return sc1.sum>sc2.sum;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Sc sc[1005];
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        sc[i].sum=a+b+c+d;
        sc[i].id=i;

    }
    sort(sc,sc+n,compare);
   
    for(int i=0;i<n;i++){
        if(sc[i].id==0){
            cout<<i+1;
            return 0;
        }
    }
}