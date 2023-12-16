#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N=10;
vector<vector<ll>> a(N);
vector<bool> visited(N,false);
void dfs(int n){
cout<<n<<" ";
visited[n]=true;
//1
for(auto i:a[n])
//2
if(!visited[i]){
  dfs(i);
  //3
}
//4
}

int main()
{
ll m=0;
cin>>m;

  for(int i=0;i<m;i++){
    ll x=0,y=0;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1);
  return 0;
}