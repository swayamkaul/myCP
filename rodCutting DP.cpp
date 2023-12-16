
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

int dp[100005];


int maxProfit(int len,vector<int>& a){
  if(len==0)return 0;

  if(dp[len]!=-1) return dp[len];
  
  int p=0;
  for(int i=1;i<=a.size();++i){
    if(len-i>=0)
    p=max(p,maxProfit(len-i,a) +a[i-1]);
  }
return dp[len]=p;
}

 int cutRod(int price[], int n) {
        vector<int> a(price,price+n);

        memset(dp,-1,sizeof(dp));

        return maxProfit(n,a);

  }

int main(){


return 0;
}