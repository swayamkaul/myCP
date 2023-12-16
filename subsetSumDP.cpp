// https://leetcode.com/problems/partition-equal-subset-sum/submissions/ 

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
vector<int> nums(N);
 int dp[205][20004];


bool subsetSum(int index, int sum,vector<int>& nums){



  if(sum==0) return true;

   if(index<0) return false;

  if(dp[index][sum]!=-1)
  return dp[index][sum];



//do nothing
  bool ans= subsetSum(index-1,sum,nums);
  //choose
  if(sum-nums[index]>=0)
  ans|=subsetSum(index-1,sum-nums[index],nums);


  return dp[index][sum]=ans;

}

bool canPartition(vector<int>& nums) {

        memset(dp,-1,sizeof(dp));

        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
            return false;
        sum=sum/2;
        return subsetSum(nums.size()-1,sum,nums);

}

int main(){



  for(int i=0;i<4;i++){
    cin>>nums[i];
  }

cout<<canPartition(nums);

return 0;
}