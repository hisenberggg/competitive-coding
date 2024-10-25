#include<bits/stdc++.h>
using namespace std;

int shortest_path(vector<vector<int>>& grid){
    int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    if(n == 1) return 1;

    queue<tuple<int,int,int>> q;
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}, 
                                      {1,-1},{-1,1},{-1,-1},{1,1}};
    int r = 0, c = 0, length = 1;
    q.push({r,c,length});

    while(!q.empty()){
        auto [r,c,length] = q.front();
        q.pop();
        if(r == n-1 && c == n-1) return length;

        for(auto it:directions){
            int row = it[0];
            int col = it[1];
            if(r+row>=n || c+col>=n || r+row<0 || c+col<0)
                continue;
            if(grid[r+row][c+col] == 0){
                q.push({r+row, c+col, length+1});
                grid[r+row][c+col] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> grid = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {0,0,0,0},
    };
    // vector<vector<int>> grid = {
    //     {0,0,0},
    //     {1,1,0},
    //     {1,1,0},
    // };

    cout<<"Shortest path is: "<<shortest_path(grid);
    return 0;
}
