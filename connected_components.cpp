#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


void dfs(int n,vector<vector<ll>>& a,vector<bool>& visited){
// cout<<n<<" ";
visited[n]=true;
//1
for(auto i:a[n])
//2
if(!visited[i]){
  dfs(i,a,visited);
  //3
}
//4
}

int main()
{
ll m=0,e=0;
cin>>e>>m;

ll N=e+1;
vector<vector<ll>> a(N);
vector<bool> visited(N,false);

  for(int i=0;i<m;i++){
    ll x=0,y=0;
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
ll count=0;
for(int i=1;i<N;i++){
	if(!visited[i]){
	count++;
 	dfs(i,a,visited);
	}
}
 cout<<count;
  return 0;
}