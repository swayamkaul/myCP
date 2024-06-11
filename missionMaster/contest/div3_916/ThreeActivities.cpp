
#include <bits/stdc++.h>
 #define forn(i, n) for (int i = 0; i < int(n); i++)
 #define gcd(a,b) __gcd(a,b)
 #define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
 
 
typedef long long ll;
int mod1=1e9+7;
const int N=1e5+10;
 
 vector<vector<int>> graph(400005);
        vector<bool> vis(400005);
ll gcd(ll a,ll b)
{
    ll c=a%b;
    while(c){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
  
 
ll power(ll x,ll n)
{
    if(n==0)       return 1;
    else if(n==1)  return x;
    else if(n%2)   return (x*power((x*x)%mod1,n/2))%mod1;
    else           return (power((x*x)%mod1,n/2));
}
 
void dfs(int i, vector<vector<int>> graph, vector<bool>& vis){
    vis[i]=true;
    for(auto x: graph[i]){
        if(!vis[x]){
            // vis[x]=true;
            dfs(x,graph,vis);
        }
    }
}

//  void gen(int n){
//     vector<vector<int>> fibs;
//     vector<int> nfib;
//     for(int i=n;i>=1;i--)
//     {
//         nfib.push_back(i);
//     }
//     fibs.push_back(nfib);
//     int dp[n+1]={0};
//     for(int i=n;i>=0;i++){
//         for(int j=0;j<=0;j++){

//         }
//     }
//  }


int main() {
   
    int t=0;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<pair<int,int>> a,b,c;
        vector<pair<int,int>> ma,mb,mc;
        for(int i=0;i<n;i++){
            int x=0;
            cin>>x;
            a.push_back({x,i});
        }
         for(int i=0;i<n;i++){
            int x=0;
            cin>>x;
            b.push_back({x,i});
        }
         for(int i=0;i<n;i++){
            int x=0;
            cin>>x;
            c.push_back({x,i});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());

        for(int i=n-1;i>n-4;i--){
            ma.push_back(a[i]);
            mb.push_back(b[i]);
            mc.push_back(c[i]);
        }
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(ma[i].second != mb[j].second && ma[i].second != mc[k].second &&
                    mb[j].second != mc[k].second){
                        ans = max(ans,ma[i].first + mb[j].first + mc[k].first);
                    }
                }
            }
        }
        cout<<ans<<"\n"; 
        
    }
    return 0;
}