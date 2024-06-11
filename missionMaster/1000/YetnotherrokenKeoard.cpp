
#include <bits/stdc++.h>
 #define forn(i, n) for (int i = 0; i < int(n); i++)
 #define gcd(a,b) __gcd(a,b)
 #define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
 
 
typedef long long ll;
int mod1=1e9+7;
const int N=1e5+10;
 
//  vector<vector<int>> graph(400005);
//         vector<bool> vis(400005);
// ll gcd(ll a,ll b)
// {
//     ll c=a%b;
//     while(c){
//         a=b;
//         b=c;
//         c=a%b;
//     }
//     return b;
// }
  
 
// ll power(ll x,ll n)
// {
//     if(n==0)       return 1;
//     else if(n==1)  return x;
//     else if(n%2)   return (x*power((x*x)%mod1,n/2))%mod1;
//     else           return (power((x*x)%mod1,n/2));
// }
 
// void dfs(int i, vector<vector<int>> graph, vector<bool>& vis){
//     vis[i]=true;
//     for(auto x: graph[i]){
//         if(!vis[x]){
//             // vis[x]=true;
//             dfs(x,graph,vis);
//         }
//     }
// }

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
        string s="";
        cin>>s;
        vector<int> del;
        stack<int> lowerr,upperr;
        lowerr.push(-1);
        upperr.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                if(lowerr.top()==-1){
                    continue;
                }else{
                   s[lowerr.top()]='b';
                    lowerr.pop();
                }
            }
            else if(s[i]=='B'){
                if(upperr.top()==-1){
                    continue;
                }else{
                    s[upperr.top()]='B';
                    upperr.pop();
                }
            }

            else if(s[i]>='a'&&s[i]<='z'){
                lowerr.push(i);
            }
            else if(s[i]>='A'&&s[i]<='Z'){
                upperr.push(i);
            }

        }

        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='b'&&s[i]!='B'){
                ans.push_back(s[i]);
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}