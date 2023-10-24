#include <bits/stdc++.h>

using namespace std;

// using recursion
int lcs(string& a, string& b, int m, int n){
    if(m<0 || n<0){  // if either pointer reacher beyond 0 then return length as 0 (no elements to compare)
        return 0;
    }
    if(a[m] == b[n]){   // if element matches the include it in the length and decrement pointers
        return 1 + lcs(a,b,m-1,n-1);
    }
    // if element doesnt match then choose the max among the m-1,m and m,n-1
    return max(lcs(a,b,m-1,n), lcs(a,b,m,n-1));
}

// using topdown - dp
int lcs_dp(string& a, string& b, int m, int n, vector<vector<int>>& dp){
    if(m<0 || n<0){  // if either pointer reacher beyond 0 then return length as 0 (no elements to compare)
        return 0;
    }
    if(dp[m][n] != -1) 
        return dp[m][n]; 

    if(a[m] == b[n]){   // if element matches the include it in the length and decrement pointers
        return dp[m][n] = 1 + lcs_dp(a,b,m-1,n-1,dp);
    }
    else{          // if element doesnt match then choose the max among the m-1,m and m,n-1
        return dp[m][n] = max(lcs_dp(a, b, m-1, n, dp), lcs_dp(a, b, m, n-1, dp));
    }
}

// using memoization
int lcs_mem(string& a, string& b, int m, int n, vector<vector<int>>& dp){
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
    string a = "abcde";
    string b = "bdqek";

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m,vector<int>(n,-1));
    // cout<<"Longest common subseq using recursion is: "<<lcs(a,b,m-1,n-1)<<endl;
    // cout<<"Longest common subseq using dp is: "<<lcs_dp(a,b,m-1,n-1,dp)<<endl;

    // shift of origin since index -1 is not possible in matrix.. dp_size (m+1)x(n+1) and call for- m,n instead of m-1,n-1
    vector<vector<int>> dp1(m+1,vector<int>(n+1,-1)); 

    cout<<"Longest common subseq using memoization is: "<<lcs_mem(a,b,m,n,dp1)<<endl;

    for(auto p:dp1){
        for(auto q:p)
        cout<<q;
        cout<<endl;
    }

    // extract_lcs(a,b,m,n,dp);
    cout<<"LCS extracted: "<<extract_lcs(a,b,m,n,dp1)<<endl;

    return 0;
}
