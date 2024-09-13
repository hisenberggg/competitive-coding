#include<bits/stdc++.h>
using namespace std;

int get_max_subsequence(vector<int> &arr, int ind, int prev_ind, vector<vector<int>> &dp){
    if(ind==arr.size()){
        return 0;
    }
    if(dp[ind][prev_ind+1] != -1) 
        return dp[ind][prev_ind+1];

    int notake = 0 + get_max_subsequence(arr,ind+1,prev_ind, dp);

    int take = 0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
        take = 1 + get_max_subsequence(arr,ind+1,ind, dp);
    }

    return dp[ind][prev_ind+1] = max(take,notake);
}

int main() {
	// your code goes here
    vector<int> arr = {0,1,0,3,2,3};
    int n = arr.size();
    int ind = 0;
    int prev_ind = -1;
    vector<vector<int>> dp(n,vector<int>(n+1,-1));

    cout<<"Max len of increasing sequence is: "<<get_max_subsequence(arr,ind, prev_ind, dp);

    return 0;
}

