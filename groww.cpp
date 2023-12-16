#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a ={{2,1,1},{1,1,0},{0,1,1}};

vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int x, int y, int n, int m){
    if(x<0 ||y<0 ||x>=n ||y>=m){

    } return false ;
    else 
    {
    if(a[x][y] == 1) return true;
    else 
    return false;
     }
}



int bfs(queue<pair<int,int>> q){

    
        int n= a.size(),m=a[0].size();
        int max_level=0;

    while(!q.empty()){
// x , 1 2 3 
    auto current_ele = q.front();
        q.pop();

    for(auto directions: dir){

        int x =current_ele.first+directions.first;
        int y = current_ele.second+directions.second;

        if(isValid(x,y,n,m){
            q.push({x,y});
        }
       
    }

    }
}

int main(){
   queue<pair<int,int>> q;
   int n= a.size(),m=a[0].size();
   
   for(int i=0;i<a.size();i++){
       for(int j=0;j<a[0].size();j++){
           if(a[i][j]==2)
           q.push({i,j});
       }
   }    
   bfs(q);


    return 0;
}


