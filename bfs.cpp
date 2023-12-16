#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N=1e5+10;
vector<vector<ll>> a(N);
vector<bool> visited(N,false);

vector<int> level(N,0);

void bfs(int vertex){
 
    queue<int> q;
    q.push(vertex);
    visited[vertex]=1;

    while(!q.empty()){
        
        int cur=q.front();
        cout<<cur<<" ";
        q.pop();
        for(auto child: a[cur]){
            if(!visited[child]){
            q.push(child);
            visited[child]=1;
            level[child]=level[cur]+1;
            }
            
        }
    }
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

  bfs(1);
cout<<"\n";
  for(int i=1;i<=m;i++){
      cout<<i<<" : "<<level[i]<<"\n";
  }

  return 0;
}