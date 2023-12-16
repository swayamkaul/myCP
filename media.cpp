
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
//         for(int j=0;j<)
//     }
//  }

char* strip(char* s,int n){
int flag=0;
int len=0;
    char ans[n];
   for(int i=n-1;i>=0;i++){
       if(s[i]!=' '){   //last char that is not space
           flag=1;
           ans[n-i]=s[i];
           len++;
       }
       if(flag){
           ans[i]=s[i];
           len++;
       }
   }

  
   return ans;

}

int main() {
   
   string s="sadfsdfha    ";
    int flag=0;
    string ans="";
   for(int i=s.length()-1;i>=0;i++){
       if(s[i]!=' '){   //last char that is not space
           flag=1;
           ans.push_back(s[i]);
       }
       if(flag){
           ans.push_back(s[i]);
       }
   }

   reverse(ans.begin(),ans.end());
    return 0;
}