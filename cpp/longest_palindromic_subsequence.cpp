#include<bits/stdc++.h>
using namespace std;

int LPS(string& a, string& b, int m, int n, vector<vector<int>>& dp){
    // base case 
    for(int i = 0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i<=n; i++){
        dp[0][i] = 0;
    }

    // rec -> table
    for(int i = 1; i <= m ; i++){

        for(int j = 1; j <= n ; j++){

            if(a[i-1] == b[j-1]){  
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }
    return dp[m][n];
}

string extract_lcs(string a, string b, int m, int n, vector<vector<int>>& dp){
    string s = "";
    while(m > 0 && n > 0){
        if(dp[m-1][n] == dp[m][n-1]){
            s += a[m-1];
            m--;n--;
        }
        else{
            if(dp[m-1][n] > dp[m][n-1]){
                m--;
            }
            else{
                n--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string s = "abbcba";
    string rev = s;
    int n = s.length();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    reverse(rev.begin(),rev.end());
    int len = LPS(s, rev, n, n, dp);

    // for(auto p:dp){
    //     for(auto q:p)
    //     cout<<q;
    //     cout<<endl;
    // }
    cout<<extract_lcs(s,rev,n,n,dp);

    return 0;
}
