/* https://codeforces.com/contest/295/problem/B */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int N=1e3+10;
int INF=1e9+10;
// vector<vector< pair<int,int>> > g(N);

// vector<int> depth(N,0),height(N,0);
// vector<int> subtreesum(N,0);
// vector<int> evensum(N,0);
// void dfs(int vertex,int par=0){
// // cout<<n<<" ";
// //1
// subtreesum[vertex]+=vertex;
// if(vertex%2==0) evensum[vertex]++;
// for(auto i:a[vertex]){
// if(i==par)continue;
// //2
//   depth[i]=depth[vertex]+1;
//   dfs(i,vertex);
//   height[vertex]=max(height[vertex],height[i]+1);
//   subtreesum[vertex]+=subtreesum[i];
//   evensum[vertex]+=evensum[i];
//   //3
// }
// //4
// }


// int _01bfs(int n){
//   deque<int> q;
//   vector<int> level(N+1,INF);
//   int cur=1;
//   level[1]=0;
//   q.push_back(1);
//   while(!q.empty()){
//     cur=q.front();
//     q.pop_front();
//     for(auto &child: a[cur]){
//       int val=child.first;
//       int wt= child.second;
//     if(level[cur]+wt<level[val]){
//       if(wt==1){
//         q.push_back(val);
//         level[val]=level[cur]+wt;
//       }
//       else{
//         q.push_front(val);
//         level[val]=level[cur];
//       }
//     }
//     }
//   }
//   return level[n]==INF?-1:level[n];
// }



  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     if(dist[i][j]==INF)
  //     cout<<"I ";
  //     else
  //     cout<<dist[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
// }


int main()
{
int n=0;
cin>>n;
vector<vector<ll>> dist(n+1,vector<ll> (n+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>dist[i][j];
    }
  }
vector<ll> delo(n);
for(int i=0;i<n;i++){

    cin>>delo[i];

}

reverse(delo.begin(),delo.end());
vector<ll> ans;

for(int k=0;k<n;k++){
  ll vert= delo[k];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      ll newdist= dist[i][vert]+dist[vert][j];
      dist[i][j]=min(dist[i][j],newdist);
    }
  }
ll sum=0;
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k;j++){
      sum+= dist[delo[i]][delo[j]];
    }
  }
ans.push_back(sum);
}

reverse(ans.begin(),ans.end());
for(auto val:ans){
  cout<<val<<" ";
}

  return 0;
}
