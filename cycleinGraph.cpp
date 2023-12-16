#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N=10;
vector<vector<ll>> a(N);
vector<bool> visited(N,false);
bool dfs(int n,int par){
// cout<<n<<" ";
bool curr=false;
visited[n]=true;
//1
for(auto i:a[n]){
//2
if(i==par)continue;

if(visited[i]){
    return true;
}
if(!visited[i]){
    curr|=dfs(i,n);
 
  //3
}
}
return curr ;
//4 
}

int main()
{
ll m=0,e=0;
cin>>m;

  for(int i=0;i<m;i++){
    ll x=0,y=0;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
bool loopExhist=false;
  for(int i=0;i<visited.size();i++){
      if(!visited[i])
        {
            if(dfs(i,-1)){
                loopExhist=true;
            }
        }
  }

  if(loopExhist)
  cout<<"cycle";
  else
  cout<<"no cycle";

  return 0;
}