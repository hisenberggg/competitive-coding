#include<bits/stdc++.h>
using namespace std;

int get_rotting_time(vector<vector<int>> &grid, int n, int m){
    queue<pair<int,int>> rotten;
    int total = 0;
    // count the total 1s and 2s and push the rotten in queue 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0) continue;
            if(grid[i][j]==2){
                rotten.push({i,j});
            }
            total++;
        }
    }
    
    int count = 0;
    int days = 0;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    // in bfs, iterate while the queue is not empty and 
    // push the adjacent ones in the queue inside the loop
    while(!rotten.empty()){
        int k = rotten.size();
        count += k;
        while(k--){
            int nx = rotten.front().first, ny = rotten.front().second;
            rotten.pop();
            for(int i=0;i<4;i++){
                int x = nx+dx[i], y = ny+dy[i];
                if(x<0 || y<0 || x>=n || y>=m || grid[x][y] != 1) 
                    continue;
                grid[x][y] = 2;
                rotten.push({x,y});
            } 
        }
        if(!rotten.empty()) days++;
    }
    // if all the oranges are rotten return days else -1 
    return count == total? days:-1;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int n = grid.size();
    int m = grid[0].size();

    int output = get_rotting_time(grid,n,m);

    cout<<"Number of days required to rot all oranges is: "<<output;
    return 0;
}