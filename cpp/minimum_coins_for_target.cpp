#include<bits/stdc++.h>
using namespace std;

int get_coins(vector<int> &coins, int ind, int val){
    if(ind==0){
        if(val%coins[ind]==0){
            return val/coins[ind];
        }
        else{
            return 1e9;
        }
    }
    int no_take = 0 + get_coins(coins,ind-1,val);
    int take = INT_MAX;
    if(coins[ind]<=val){
        take = 1 + get_coins(coins,ind,val-coins[ind]);
    }
    return min(no_take,take);
}

int get_coins_dp(vector<int> &coins, int ind, int val, vector<vector<int>> &dp){
    if(ind==0){
        if(val%coins[ind]==0){
            return val/coins[ind];
        }
        else{
            return 1e9;
        }
    }

    if(dp[ind][val] != -1){
        return dp[ind][val];
    }

    int no_take = 0 + get_coins_dp(coins,ind-1,val,dp);
    int take = INT_MAX;
    if(coins[ind]<=val){
        take = 1 + get_coins_dp(coins,ind,val-coins[ind],dp);
    }
    return dp[ind][val] = min(no_take,take);
}

int get_coins_tabulation(vector<int> &coins, int ind, int val, vector<vector<int>> &dp){
    
    for(int i=0;i<=val;i++){
        if(i%coins[0]==0){
            dp[0][i] = i/coins[0]; 
        }
        else{
            dp[0][i] = 1e9;
        }
    }

    for(int i=1;i<ind;i++){
        for(int j=0;j<=val;j++){
            int no_take = 0 + dp[i-1][j];
            int take = INT_MAX;
            if(coins[i]<=j){
                take = 1 + dp[i][j-coins[i]];
            }
            dp[i][j] = min(take,no_take);
        }
    }
    return dp[ind-1][val];
}

int main(){
    vector<int> coins = {9,6,5,1};
    int V = 11;
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(V+1,0));

    // int count = get_coins(coins,n-1,V);
    // int count = get_coins_dp(coins,n-1,V,dp);
    int count = get_coins_tabulation(coins,n,V,dp);
    
    cout<<"Minimum coins required: "<<count<<endl;

    for(auto it:dp){
        for(auto its:it){
            cout<<its<<" ";
        }
        cout<<endl;
    }

    return 0;
}