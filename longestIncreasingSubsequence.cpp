
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e6+10;
const int INF = 1e9+10;

// int k=0;

// int h[N];

int dp[N];
// int pts[N][3];
// int ha=0;

vector<int> a(N);

int rec (int n){
 int cost=1;
if(dp[n]!=-1)
return dp[n];
 for(int i=0;i<n;i++){
   if(a[n]>a[i]){
     cost=max(cost,rec(i)+1);
   }
 }

 return dp[n]=cost;

}



int main()
{
  int n=0;
  cin>>n;
  memset(dp,-1,sizeof(dp));

  for(int i=0;i<n;i++){
   cin>>a[i];
  }

int maxx=0;
for(int i=0;i<n;i++){
maxx=max(maxx,rec(i));
}
  cout<<maxx;
  return 0;
}
