// https://youtu.be/myPeWb3Y68A
// unbounded knapsack
// choose minimum number of coins to get the amount required

#include<bits/stdc++.h>
using namespace std;

int coinchange_mem(vector<int> coins, int amount, int ind, vector<vector<int>>& dp){
    if(ind == 0){
        if(amount % coins[ind] == 0) return amount/coins[ind];
        else return INT_MAX;   
    }
    if(dp[ind][amount] != -1) return dp[ind][amount]; 

    int nottake = coinchange_mem(coins, amount, ind-1, dp);
    int take = INT_MAX;
    if(coins[ind] <= amount){
        take = 1 + coinchange_mem(coins, amount - coins[ind], ind, dp); 
    }
    return dp[ind][amount] = min(take, nottake);
}

int coinchange_tabu(vector<int> coins, int amount, int n, vector<vector<int>>& dp){
    for(int amt = 0; amt<=amount; amt++){
        if(amt%coins[0] == 0) 
            dp[0][amt] = amt/coins[0];
        else dp[0][amt] = 1e9;
    }

    for(int ind = 1; ind<=n; ind++){
        for(int amt=0; amt<=amount; amt++){
            int nottake = dp[ind-1][amt];
            int take = 1e9;
            if(coins[ind] <= amt){
                take = 1 + dp[ind][amt - coins[ind]]; 
            }
            dp[ind][amt] = min(take, nottake);
        }
    }
    
    // cout<<"Test: "<<dp[n][amount];
    return dp[n][amount];
}

int coinchange_opt_tabu(vector<int> coins, int amount, int n){
    vector<int> prev(amount+1,0), cur(amount+1,0);
    for(int amt = 0; amt<=amount; amt++){
        if(amt%coins[0] == 0) 
            prev[amt] = amt/coins[0];
        else prev[amt] = 1e9;
    }

    for(int ind = 1; ind<=n; ind++){
        for(int amt=0; amt<=amount; amt++){
            int nottake = prev[amt];
            int take = 1e9;
            if(coins[ind] <= amt){
                take = 1 + cur[amt - coins[ind]]; 
            }
            cur[amt] = min(take, nottake);
        }
        prev = cur;
    }

    // cout<<"Test: "<<prev[amount];
    return prev[amount];
}

int main()
{
    vector<int> coins = {1,2,5};
    int n = coins.size();
    int amount = 20;
    
    // memoization
    // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    // int op = coinchange_mem(coins, amount, n - 1, dp);

    // tabulation
    // vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
    // int op = coinchange_tabu(coins, amount, n, dp);

    // optimized tabulation
    int op = coinchange_opt_tabu(coins, amount, n);

    if(op>=INT_MAX || op<=-INT_MAX) cout<<"Coins: "<<-1<<endl;
    else cout<<"Coins: "<<op<<endl;

    // print matrix
    // for(auto a: dp){
    //     for(auto b:a) cout<<b<<" ";
    //     cout<<endl;
    // }

    return 0;
}
