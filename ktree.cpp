#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

 const int N = 1e5+10;
// const int INF = 1e9+10;

const int mod=1e9+7;
int n=0,k=0,d=0;
ll dp[105][2];

ll ways(int sumleft,int taken){

    if(sumleft<0)
    return 0LL;

    if(sumleft==0&&taken==1)
    return 1LL;
   
    if(sumleft==0&&taken ==0)
    return 0LL;

    if(dp[sumleft][taken]!=-1)
    return dp[sumleft][taken];

    ll ans=0;

    for(int i=1;i<=k;i++){
        
        ans+= ways(sumleft-i,taken==1 || i>=d?1:0 );
    }

ans= ans%mod;

return dp[sumleft][taken]= ans%mod;

}



int main(){

memset(dp,-1,sizeof(dp));
cin>>n>>k>>d;

cout<<ways(n,0);
return 0;
}