
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

int isRemovable(string s){
vector<pair<char,int>> a;
int x=0;
int n=s.length();
for(int i=0;i<n-1;i++){
    if(s[i]==s[i+1]){
        x++;
    }
    else {
        a.push_back(make_pair(s[i],x+1));
        x=0;
    }
}
a.push_back(make_pair(s[n-1],x+1));

// cout<<"\nTEST: ";

// for(int i=0;i<a.size();i++){
//     cout<<a[i].first<<" "<<a[i].second<<"\n";
// }
// cout<<"\n";


if(a.size()&1){
    for(int i=0;i<a.size()/2;i++){
        if(a[i].first != a[a.size()-i-1].first) return 0;
        if(a[i].second + a[a.size()-i-1].second<3) return 0;
    }
    return a[a.size()/2].second<2?0:a[a.size()/2].second+1;

}else{
    return 0;
}

}


int main() {
   
    string s="";
    cin>>s;
    cout<<isRemovable(s);
    return 0;
}

