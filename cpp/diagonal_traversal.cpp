#include<bits/stdc++.h>
using namespace std;

vector<int> getDiagonalTraversal(vector<vector<int>>& matrix){
    vector<int> output;
    bool up = true;
    int n = matrix.size();
    int m = matrix[0].size();
    int diags = m + n - 1;

    int i = 0, j = 0;

    while(diags--){
        if(up){
            while(i>=0 && j<m){
                output.push_back(matrix[i][j]);
                i--;j++;
            }
            if(i<0 && j<m) 
                i++;
            if(j>=m){
                j--;i+=2;
            }
            up = false;
        }
        else{
            while(j>=0 && i<n){
                output.push_back(matrix[i][j]);
                i++;j--;
            }
            if(j<0 && i<n) 
                j++;
            if(i>=n){
                i--;j+=2;
            }
            up = true;
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> matrix = {
        {1 ,2 ,3 ,4 ,5 ,6 },
        {7 ,8 ,9 ,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
        {31,32,33,34,35,36},
    };

    vector<int> output = getDiagonalTraversal(matrix);
    for(auto it:output){
        cout<<it<<" "; 
    }
    return 0;
}
