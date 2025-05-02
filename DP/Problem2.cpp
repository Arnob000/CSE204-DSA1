//DP + Bitmasking
//Optimal cost to visit city
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[11][(1<<11)];
int cost[11][11];

int solve(int city, int mask, int n){
    if(city >= n)
        return 0;

    if(dp[city][mask] != -1)
        return dp[city][mask];

    int totalcost = INT_MAX, visited = 0;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){

            visited = 0;
            for(int j=0; j<n; j++){
                if(mask & (1<<j))
                    visited += cost[i][j];          //calculating the cost of visited city
            }

            totalcost = min(totalcost, cost[city][city]+visited+solve(city+1, mask^(1<<i), n));  //calculating minimum cost
        }
    }
    dp[city][mask] = totalcost;
    return totalcost;
}

int main(){
    int n=0;
    while(true){
        cout<<"Enter n( 0<n<=10 ): \n";
        cin>>n;
        if(n>0 && n<11)
            break;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>cost[i][j];

    memset(dp, -1, sizeof(dp));
    cout<<endl<<solve(0, 0, n)<<endl;
}
