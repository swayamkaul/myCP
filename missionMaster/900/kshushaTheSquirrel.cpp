
#include <bits/stdc++.h>
 #define forn(i, n) for (int i = 0; i < int(n); i++)
 #define gcd(a,b) __gcd(a,b)
 #define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
 
 
typedef long long ll;
int mod1=1e9+7;
const int N=1e5+10;

int main() {
   ll n=0,k=0;
   cin>>n>>k;
    string s="";
    cin>>s;
    int count = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){
            count++;
            if(count==k){
                cout<<"NO";
                return 0;
            }
        }else {
            count = 0;
        }
    }
    cout<<"YES";
    return 0;
}

