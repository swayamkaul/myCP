
#include <bits/stdc++.h>
 #define forn(i, n) for (int i = 0; i < int(n); i++)
 #define gcd(a,b) __gcd(a,b)
 #define lcm(a,b) a*b/(__gcd(a,b))
using namespace std;
 
 
typedef long long ll;
int mod1=1e9+7;
const int N=1e5+10;
 

string func(string s,string t){
    if(s.size() != t.size()) 
        return "-1";
    
    string ans =s;

    for(int i=0;i<t.size();i++){
        if(ans[i]<t[i]) 
            return "-1";
        else{
            ans[i]=t[i];
        }

    }
    return ans;

}


int main() {
   
    string s="",t="";
    cin>>s>>t;
    cout<<func(s,t);
    return 0;
}

