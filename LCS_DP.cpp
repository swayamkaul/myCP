#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

// const int N = 1e5+10;
// const int INF = 1e9+10;

int dp[1005][1005];

int lcs(int i,int j, string &s1, string &s2){

if(i<0||j<0)
return 0;

if(dp[i][j]!=-1) return dp[i][j];
  //skip 1 from s1
 int ans= lcs(i-1,j,s1,s2);

  //skip 1 from s2
  ans=max(ans,lcs(i,j-1,s1,s2));

  // skip 1 from both s1 and s2
  ans=max(ans,lcs(i-1,j-1,s1,s2)+(s1[i]==s2[j]));

  return dp[i][j]=ans;


}

int longestCommonSubsequence(string text1, string text2) {

        memset(dp,-1,sizeof(dp));
        return lcs(text1.length()-1,text2.length()-1,text1,text2);

    }

int main(){

cout<<longestCommonSubsequence("abcdef","agcgeg");
return 0;
}