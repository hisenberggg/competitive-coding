#include<bits/stdc++.h>
using namespace std;

// From starting index i, you can move to i+k. If i+k is greater then size of arr, then exit
// select the optimal starting point i, so that the sum is maximum 

// write functions here 
int get_maxsum(vector<int> arr, int k){
    int n = arr.size();
    
    vector<int> dp(arr.begin(),arr.end());

    for(int i=n-k-1;i>=0;i--){
        dp[i] = dp[i+k]+dp[i];
    }

    int maxi = INT_MIN;
    for(auto it:dp){
        maxi = max(maxi,it);
    }
    return maxi;
}

int main() {
	// your code goes here
    // vector<int> arr = {6,-3,-6,-2,-4};
    vector<int> arr = {6,-3,-6,2,-4};
    // vector<int> arr = {6,3,6,2,4};
    int k = 2;

    cout<<"Max sum is: "<<get_maxsum(arr,k);

    return 0;
}

