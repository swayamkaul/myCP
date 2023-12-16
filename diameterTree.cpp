#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N=1e5+10;
vector<vector<ll>> a(N);
vector<int> depth(N,0),height(N,0);
vector<int> subtreesum(N,0);
vector<int> evensum(N,0);
void dfs(int vertex,int par=0){
// cout<<n<<" ";

//1
subtreesum[vertex]+=vertex;
if(vertex%2==0) evensum[vertex]++;
for(auto i:a[vertex]){
if(i==par)continue;
//2
  depth[i]=depth[vertex]+1;
  dfs(i,vertex);
  height[vertex]=max(height[vertex],height[i]+1);
  subtreesum[vertex]+=subtreesum[i];
  evensum[vertex]+=evensum[i];
  //3
}
//4
}

int main()
{
ll m=0;
cin>>m;

  for(int i=0;i<m-1;i++){
    ll x=0,y=0;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1,0);
int maxdepth=-1;
int maxnode=-1;
  for(int i=1;i<=m;i++){
      if(maxdepth<depth[i])
      {
          maxdepth=depth[i];
          maxnode=i;
      }
      depth[i]=0;
  }
  //theorem: maxnode will definitely be an end of the diameter 
dfs(maxnode,0);
for(int i=1;i<=m;i++){
      if(maxdepth<depth[i])
      {
          maxdepth=depth[i];
          maxnode=i;
      }
  }

  cout<<maxdepth;//diameter
  return 0;
}