#include<bits/stdc++.h>
using namespace std;
void solve(){
        long long a,b;
        cin>>a>>b;
        int distanceA=0;
        int distanceB=0;
        unordered_map<int,int> ss;
       ss[a]=0;
        while(a){
            ss[a]=distanceA;
            distanceA++;
            a/=2;
        }
        long long ans=0;
        while(b){
            if(ss.find(b)!=ss.end()){
                ans=ss[b]+distanceB+1;
                break;
            }
            distanceB++;
            b/=2;
        }
        cout<<ans<<"\n";
    
}
int main(){
    int t=0;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}
