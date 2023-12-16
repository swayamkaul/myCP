// constraints gives hint on solving the problem within timecomplexity

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

int n=0;
ll W=0;
int V=1e5;

int coins[N];

ll dp[105][N];

vector<int> pts(N);
vector<int> w(N);

ll minweight (int index,int pointsLeft ){

if(pointsLeft==0)
return 0;

if(index<0)
return 1e11;

if(dp[index][pointsLeft]!=-1)
  return dp[index][pointsLeft];

//do Nothing
ll p=minweight(index-1,pointsLeft);
//include the current item
if(pointsLeft-pts[index]>=0)
p=min(p,minweight(index-1,pointsLeft-pts[index]) + w[index]);


return dp[index][pointsLeft]=p;
}


int main(){

 memset(dp,-1,sizeof(dp));
  cin>>n>>W;
  for(int i=0;i<n;i++){
    cin>>w[i]>>pts[i];
  }

for(int i=1e5;i>=0;i--){

  if(minweight(n-1,i)<=W){
    cout<<i;
    break;
  }
  
}

return 0;
}