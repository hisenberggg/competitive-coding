// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> row_travel = {0,1,0,-1};
    vector<int> col_travel = {1,0,-1,0};
    int row = matrix.size(), col = matrix[0].size(), r = 0, c = 0, di = 0, dr,dc;
    vector<vector<bool>> seen(row,vector<bool>(col,false));

    for(auto r:matrix){
        for(auto c: r) cout<<c<<" ";
        cout<<endl;
    }

    for(int i = 0; i<row*col; i++){
        cout<<matrix[r][c]<<endl;
        seen[r][c] = true;
        dr = r + row_travel[di];
        dc = c + col_travel[di];
        if(dr>=0 && dc>=0 && dr<row && dc<col && !seen[dr][dc]){
            r = dr;
            c = dc;
        }
        else{
            di = (di+1)%4;
            r += row_travel[di];
            c += col_travel[di];
        }
    }
    
    return 0;
}
