// https://youtu.be/HgyouUi11zk
// Find the total number of ways to get the target
#include<bits/stdc++.h>
using namespace std;

int coinchange_mem(vector<int> coins, int amount, int ind, vector<vector<int>>& dp){
    if(ind == 0){
        if(amount % coins[ind] == 0) return 1;
        else return 0;   
    }
    if(dp[ind][amount] != -1) return dp[ind][amount]; 

    int nottake = coinchange_mem(coins, amount, ind-1, dp);
    int take = 0;
    if(coins[ind] <= amount){
        take = coinchange_mem(coins, amount - coins[ind], ind, dp); 
    }
    return dp[ind][amount] = take + nottake;
}

int coinchange_tabu(vector<int> coins, int amount, int n, vector<vector<int>>& dp){
    for(int amt = 0; amt<=amount; amt++){
        dp[0][amt] = (amt%coins[0] == 0); //returns 0 if set is possible else 1    
    }

    for(int ind = 1; ind<=n; ind++){
        for(int amt=0; amt<=amount; amt++){
            int nottake = dp[ind-1][amt];
            int take = 0;
            if(coins[ind] <= amt){
                take = dp[ind][amt - coins[ind]]; 
            }
            dp[ind][amt] = take + nottake;
        }
    }
    // cout<<"Test: "<<dp[n][amount];
    return dp[n][amount];
}

int coinchange_opt_tabu(vector<int> coins, int amount, int n){
    vector<int> prev(amount+1,0), cur(amount+1,0);
    for(int amt = 0; amt<=amount; amt++){
        prev[amt] = (amt%coins[0] == 0); 
    }
    cout<<"Test: "<<prev[amount];
    for(int ind = 1; ind<=n; ind++){
        for(int amt=0; amt<=amount; amt++){
            int nottake = prev[amt];
            int take = 0;
            if(coins[ind] <= amt){
                take = cur[amt - coins[ind]]; 
            }
            cur[amt] = take + nottake;
        }
        prev = cur;
    }

    cout<<"Test: "<<prev[amount];
    return prev[amount];
}

int main()
{
    vector<int> coins = {1,2};
    int n = coins.size();
    int amount = 4;
    
    // memoization
    // vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    // int op = coinchange_mem(coins, amount, n - 1, dp);

    // tabulation
    // vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
    // int op = coinchange_tabu(coins, amount, n, dp);

    // Space optimized tabulation
    int op = coinchange_opt_tabu(coins, amount, n);

    cout<<"Number of ways to choose the coins: "<<op<<endl;

    // print matrix
    // for(auto a: dp){
    //     for(auto b:a) cout<<b<<" ";
    //     cout<<endl;
    // }

    return 0;
}