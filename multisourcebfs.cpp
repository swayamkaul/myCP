#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int N=1e3+10;
int INF=1e9+10;
vector< vector<int>> a(N,vector<int> (N));
vector< vector<int>> level(N,vector<int> (N,-1));
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

bool isValid(int i,int j){
  if(i<0||j<0||i>n||j>m)
  return false;
  else
  return true;
}

int bfs(){
  int maxx=INT_MIN;
  queue <pair<int,int>> q;
  vector<pair<int,int>> movements={
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {1,1},{-1,-1}, {-1,1}, {1,-1}
  };

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     maxx=max(maxx,a[i][j]);
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(a[i][j]==maxx){
       level[i][j]=0;
       q.push({i,j});
     }
    }
  }
 pair<int,int> curv;
 while(!q.empty()){
   curv=q.front();

   q.pop();

   int ii=curv.first;
   int jj=curv.second;

   for(int i=0;i<movements.size();i++){

     int childi = ii+movements[i].first;
     int childj = jj+movements[i].second;

     if(isValid(childi,childj)){
       
       if(a[childi][childj]<a[ii][jj]){
         a[childi][childj]=a[ii][jj];
          level[childi][childj]=level[ii][jj]+1;

          q.push({childi,childj});
       }
       

     }


   }

 }

 int maxlevel=0;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     maxlevel=max(maxlevel,level[i][j]);
    }
  }

return maxlevel;

}



void reset(){

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      a[i][j]=0;
      level[i][j]=0;
    }
  }
}

int main()
{
int t=0;
cin>>t;
while(t--){
cin>>n>>m;
reset();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
    
  }
  
cout<<bfs()<<"\n";

}

  return 0;
}