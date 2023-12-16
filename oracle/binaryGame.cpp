#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int fact[10009];

long long power(long long x,long long n)
{
    if(n==0)       return 1;
    else if(n==1)  return x;
    else if(n%2)   return (x*power((x*x)%mod,n/2))%mod;
    else           return (power((x*x)%mod,n/2));

}

int main(){
    int minl=2,maxl=5,zg=2,og=3;

    int ans=0;
    fact[0]=1;
    fact[1]=1;

    for(int i=2;i<10009;i++){
        fact[i]= (fact[i-1]*i*1LL)%mod;
    }
    
    for(int i=minl;i<=maxl;i++){
        int temp=0;
        int flag=0;
        if(i%zg==0){
            flag=(flag+1+0LL)%mod;
            
        }
        if(i%og==0){
            temp=(temp+1+0LL)%mod;
        }

        if(i%(og+zg)==0){
           
            if(og!=zg){
               int n= i/(og+zg);
               temp+= (fact[n]/(fact[n/2]*fact[n/2]));
            }else{
                int n= i/og;
                long long x= power(2,n)-2;
                temp+=x;
            }
        }


        ans+=temp;
        
    }


    cout<<ans<<"\n";
    return 0;
}