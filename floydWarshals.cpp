#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int N=1e3+10;
int INF=1e9+10;
// vector<vector< pair<int,int>> > g(N);
int n=0, m=0;
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

vector<vector<int>> dist(N,vector<int>(N));

void floydWarshals(int n){



  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(dist[i][k]!=INF && dist[k][j]!=INF)
        dist[i][j]= min(dist[i][k]+dist[k][j], dist[i][j]);
      }
    }
  }


  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     if(dist[i][j]==INF)
  //     cout<<"I ";
  //     else
  //     cout<<dist[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
}


int main()
{
int x=0,y=0,w=0;
cin>>n>>m;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)
      dist[i][j]=0;
      else
      dist[i][j]=INF;
    }
  }

for(int i=0;i<m;i++){

    cin>>x>>y>>w;
    dist[x][y]= w;

}



floydWarshals(n);

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(dist[i][j]==INF)
      cout<<"I ";
      else
      cout<<dist[i][j]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}