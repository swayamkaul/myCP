
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
 
// void dfs(int i, vector<vector<int>> graph, vector<bool>& vis){
//     vis[i]=true;
//     for(auto x: graph[i]){
//         if(!vis[x]){
//             // vis[x]=true;
//             dfs(x,graph,vis);
//         }
//     }
// }



int main() {
   
    ll n=0;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n&1){
            n=(n*3+1);
        }else{
            n/=2;
        }
        cout<<n<<" ";
    }
    
    return 0;
}