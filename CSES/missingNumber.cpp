
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
 


int main() {
   
    ll n=0;
    cin>>n;
    ll summ=(n*(n+1))/2;
    ll sum2=0;
    
    for(int i=0;i<n-1;i++){
        int x=0;
        cin>>x;
        sum2+=x;
    }
    cout<<summ-sum2;
    return 0;
}