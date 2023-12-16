#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N=1e5+10;
vector<vector<ll>> a(N);
vector<int> para(N,0);

void dfs(int vertex,int par=-1){
// cout<<n<<" ";

//1
para[vertex]=par;
for(auto i:a[vertex]){
    if(i==par)continue;
    //2
    dfs(i,vertex);
    //3
}
//4
}

vector<int> path(int vertex){

    vector<int> a;
    while(vertex!=-1){
        a.push_back(vertex);
        vertex=para[vertex];
    }
    reverse(a.begin(),a.end());

    return a;
}

int lcaa(vector<int>& p1,vector<int>& p2){

    int mn_len=min(p1.size(),p2.size());
    int lca=-1;
    for(int i=0;i<mn_len;i++){
        if(p1[i]==p2[i]){
            lca=p1[i];
        }
        else break;
    }

    return lca;
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
    dfs(1,-1);

    int xx=0,yy=0;
    cin>>xx>>yy ;

    vector<int> p1 = path(xx) ;

    vector<int> p2 = path(yy) ;

    cout<<lcaa(p1,p2);

  return 0;
}