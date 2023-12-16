
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
int n=0,k=0;
cin>>n>>k;
for(int i=1;i<=n;i++){
  make(i);
}
while(k--){
  int u,v;
  cin>>u>>v;
  Union(u,v);
}

int connected_ct=0;

for(int i=1;i<=n;++i){
  if(parent[i]==i)
  connected_ct++;
}

cout<<connected_ct<<"\n";
  return 0;
}
