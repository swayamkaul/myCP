#include<bits/stdc++.h>
using namespace std;
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// int a[50][50];
// bool check(int x,int y,int n,int m){
//     if(x<0 || y<0 || x>=n || y>=m || a[x][y]==-1)return false;
//     return true;
// }
// int dp[40][40][1600];
// int helper(int n,int m,int x,int y,int k){
//  //   if(x==n-1 && y==m-1)return dp[x][y][k]=0;
//     if(x==n-1 && y==m-1)return 0;
// //    if(dp[x][y][k]!=-1)return dp[x][y][k];
//     int ans=1e6;
//     int pre=a[x][y];
//     a[x][y]=-1;
//     for(int i=0;i<4;i++){
//         int newx=x+dx[i];
//         int newy=y+dy[i];
//         if(check(newx,newy,n,m)){
            
//             int temp=1e6;
//             if(a[newx][newy]==1){
//                 if(k){
//                     temp=1+helper(n,m,newx,newy,k-1);
//                 }
//             }
//             else{
//                 temp=1+helper(n,m,newx,newy,k);
//             }
//             ans=min(ans,temp);
//         }
//     }
//     a[x][y]=pre;
//   //  return dp[x][y][k]= ans;
//         return ans;
// }

// int shortestPath(int n,int m, int k) {
//     memset(dp,-1,sizeof(dp));
//     int ans=helper(n,m,0,0,k);
//     if(ans>=1e6)return -1;
//     return ans;
// }
int main(){
    int n=4;
    int arr[4]={1,1,2,3};
    int sum=1;
    int dp[n+1][sum+1];

    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n+1;i++){

        for(int j=0;j<sum+1;j++){

            if(i==0) dp[i][j]=0;
            if(j==0)dp[i][j]=1;
            else if(i==0){cout<<dp[i][j]<<" ";continue;}
            else if( arr[i-1]<=j){
               dp[i][j]= dp[i-1][j-arr[i-1]]+ dp[i-1][j];
            }else {
           
                dp[i][j]=dp[i-1][j];
            }

            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
        
    }
    cout<<dp[4][1]<<" ";
    return 0;
}