
#include <bits/stdc++.h>
 #define forn(i, n) for (int i = 0; i < int(n); i++)
 #define gcd(a,b) __gcd(a,b)
 #define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
 
 
typedef long long ll;
int mod1=1e9+7;
const int N=1e5+10;

bool cmp(pair<int,int> x, pair<int,int> y){
    if(x.first!=y.first){
        return x.first<y.first;
    }else{
        return x.second>y.second;
    }
    
}

int main() {
   ll n=0,k=0;
   cin>>n>>k;
   vector<ll> a(n);
   vector<ll> b(n);
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   vector<pair<ll,ll>> c;
   for(int i=0;i<n;i++){
       cin>>b[i];
       c.push_back({a[i],b[i]});
   }

   sort(c.begin(),c.end(),cmp);

//    for(int i=0;i<n;i++){
//        cout<<c[i].first <<" "<<c[i].second<<"\n";
//    }
   ll count=0;
   vector<ll> vis(n+1,-1);
   vector<ll> xyz;

   for(ll i=0;i<n;i++){
       if(vis[c[i].first]==-1){
           vis[c[i].first]=0;
           count++;
       }else{
           xyz.push_back(c[i].second);
       }
   }

   ll ans=0;
   sort(xyz.begin(),xyz.end());

   for(ll i=0;i<k-count;i++){
       ans+=xyz[i];
   }
   cout<<ans;
    
    return 0;
}

