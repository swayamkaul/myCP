
#include <bits/stdc++.h>

using namespace std;
 vector<int> a(26,0);
 
 int solution(string &s){
    int count=0;
    for(auto x: s){
        a[x-'a']++;
    }
    for(int i=0;i<26;i++){
        if(a[i]&1) count++;
    }
    return count;
 }


int main() {
   
   string s="";
   cin>>s;

    cout<<solution(s);
   
    return 0;
}