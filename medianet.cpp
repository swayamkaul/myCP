#include<bits/stdc++.h>
using namespace std;
vector<int> fun()
{
        int markets; 
        cin>>markets;
        vector<int>costs(markets+1);
        for(int i=1; i<=markets; i++)cin>>costs[i];

        //number of roads
        int n; 
        cin>>n;
        vector<vector<int>>emptycost(markets+1, vector<int>(markets+1, INT_MAX));
        vector<vector<int>>fullcost (markets+1, vector<int>(markets+1, INT_MAX));
        for(int i=0;i<n; i++)
        {
            int city1 ,city2 ,price ,tax;
            cin>>city1>>city2>>price>>tax;
            emptycost[city1][city2]=price;  emptycost[city2][city1]=price;
            fullcost[city1][city2]=tax*price; fullcost[city2][city1]=tax*price;
        }
        for(int i=1; i<=markets; i++){emptycost[i][i]=0; fullcost[i][i]=0;}
        for (int k = 1; k <=markets; k++) {
            for (int i = 1; i <=markets; i++) {
                for (int j = 1; j <=markets; j++) {

                    if ( emptycost[k][j] != INT_MAX && emptycost[i][k] != INT_MAX && 
                                    emptycost[i][j] > (emptycost[i][k] + emptycost[k][j]))
                        emptycost[i][j] = emptycost[i][k] + emptycost[k][j];
                    if ( fullcost[k][j] != INT_MAX && fullcost[i][k] != INT_MAX &&  
                                     fullcost[i][j] > (fullcost[i][k] + fullcost[k][j]) )
                        fullcost[i][j] = fullcost[i][k] + fullcost[k][j];
                }
            }
        }
        vector<int>res;
        for(int i=1; i<=markets; i++)
        {
            int cost=costs[i];
            for(int j=1; j<=markets; j++)
            {
                if(i==j)continue;
                int c= emptycost[i][j]+fullcost[j][i]+costs[j];
                cost=min(cost, c);
            }
            res.push_back(cost);
        }
        return res;
    }