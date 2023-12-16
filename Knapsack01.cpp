
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

int n=0;
int W=0;


int coins[N];

ll dp[101][N];

vector<int> pts(N);
vector<int> w(N);

ll profit (int index,int amount ){    //recursive memoized 

if(index<0)
return 0LL;
if(amount<=0)
return 0LL;

if(dp[index][amount]!=-1)
  return dp[index][amount];

ll p=0;
//do Nothing
p=profit(index-1,amount);
//include the current item
if(amount-w[index]>=0)
p=max(p,profit(index-1,amount-w[index]) + pts[index]);


return dp[index][amount]=p;
}


int main(){

 memset(dp,-1,sizeof(dp));
  cin>>n>>W;
  for(int i=0;i<n;i++){
    cin>>w[i]>>pts[i];
  }

cout<<profit(n-1,W);
}
// topDown
// int main(){      
//     int n=4;
//     int arr[4]={1,1,2,3};
//     int sum=1;
//     int dp[n+1][sum+1];

//     memset(dp,0,sizeof(dp));
    
//     for(int i=0;i<n+1;i++){

//         for(int j=0;j<sum+1;j++){

//             if(i==0) dp[i][j]=0;
//             if(j==0)dp[i][j]=1;
//             else if(i==0){cout<<dp[i][j]<<" ";continue;}
//             else if( arr[i-1]<=j){
//                dp[i][j]= dp[i-1][j-arr[i-1]]+ dp[i-1][j];
//             }else {
           
//                 dp[i][j]=dp[i-1][j];
//             }

//             cout<<dp[i][j]<<" ";
//         }
//         cout<<"\n";
        
//     }
//     cout<<dp[4][1]<<" ";
//     return 0;
// }
