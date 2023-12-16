#include <bits/stdc++.h>
 
using namespace std;
 typedef long long ll;
vector<bool> primes(1e5+1,true);
vector<ll> hp(1e5+1,0);
vector<ll> lp(1e5+1,0);
 void sieve(ll n){
    primes[0]=primes[1]=false;
    for(ll i=2;i<n;i++){
        if(primes[i]){
            hp[i]=lp[i]=i;
            for(ll j=i*2;j<n;j+=i){
            primes[j]=false;
            hp[j]=i;
            }

        }
    }
 }
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a=0,b=0;
    cin>>a>>b;
    map<ll,ll> pfa;
    map<ll,ll> pfb;
    sieve(max(a,b)+1);
    // for(int i=0;i<100;i++){
    //     cout<<i<<" "<<hp[i]<<"\n";
    // }
    
    while(a>1){
        ll prime_factor=hp[a];
        while(a%prime_factor==0){
            pfa[prime_factor]++;
            a/=prime_factor;
        }
    }

     while(b>1){
        ll prime_factor=hp[b];
        while(b%prime_factor==0){
            pfb[prime_factor]++;
            b/=prime_factor;
        }
    }
    // cout<<"\npfa:\n";
    for(auto factor: pfa){
    cout<<factor.first<<" "<<factor.second<<"\n";
    }
      
    for(auto factor: pfb){
    cout<<factor.first<<" "<<factor.second<<"\n";
    }


    return 0;
     }
