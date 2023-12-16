
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=1e6+10;
const int INF=1e9+10;

int parent[N];
int Size[N];

void make(int n){
  parent[n]=n;
  Size[n]=1;
}

int find(int n){
  if(parent[n]==n)
  return n;
  return parent[n]= find(parent[n]);  //path compression optimisation
}

void Union(int a, int b){
a= find(a);
b= find(b);

if(a!=b){
  if(Size[a]<Size[b])     // size optimisation
  swap(a,b);
  parent[b]=a;
  Size[a]+=Size[b];
}

}

int main()
{
int n=0,m=0;
cin>>n>>m;

vector<pair<int,pair<int,int>>> a;
for(int i=1;i<=n;i++){
  make(i);
}
while(m--){
  int u,v,w;
  cin>>u>>v>>w;
  a.push_back({w,{u,v}});
}

sort(a.begin(),a.end());
int cost=0;
for(int i=0;i<a.size();i++){
  int wt= a[i].first;
  int u= a[i].second.first;
  int v= a[i].second.second;

  if(find(u)==find(v))
  continue;

  Union(u,v);

  cost+=wt;
cout<<u<<" "<<v<<"\n";
}
cout<<cost;
  return 0;
}
