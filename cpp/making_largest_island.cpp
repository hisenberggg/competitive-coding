#include<bits/stdc++.h>
using namespace std;

int getMergedArea(vector<vector<int>>& grid, int i, int j, int n, unordered_map<int,int> island_size){
    set<int> islands;
    if(i+1<n && grid[i+1][j] != 0){  // explore 4 directions to check if island exist
        islands.insert(grid[i+1][j]); // if found insert in island set
    }
    if(i-1>=0 && grid[i-1][j] != 0){
        islands.insert(grid[i-1][j]);
    }
    if(j+1<n && grid[i][j+1] != 0){
        islands.insert(grid[i][j+1]);
    }
    if(j-1>=0 && grid[i][j-1] != 0){
        islands.insert(grid[i][j-1]);
    }
    int area = 0;
    for(auto it:islands){ // calculate the total island area
        area += island_size[it];
    }

    return area+1; // +1 for including self
}

int islandSize(vector<vector<int>>& grid, int i, int j, int n, 
                                                    vector<vector<int>>& visited, int id){
    
    if(i<0 || j<0 || i>=n || j>= n || grid[i][j]==0 || visited[i][j] == 1) 
        return 0;

    visited[i][j] = 1;
    grid[i][j] = id;

    return 1 + 
    islandSize(grid,i+1,j,n,visited,id) + 
    islandSize(grid,i,j+1,n,visited,id) + 
    islandSize(grid,i-1,j,n,visited,id) + 
    islandSize(grid,i,j-1,n,visited,id) ;
}

int makeLargestIsland(vector<vector<int>>& grid){
    int n = grid.size();
    unordered_map<int,int> island_size;
    int id = -2;

    int maxIslandSize = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                vector<vector<int>> visited(n,vector<int>(n,0));
                int size = islandSize(grid,i,j,n,visited, id);
                island_size[id] = size;
                maxIslandSize = max(maxIslandSize,size);
                id--;
            }
        }
    }

    int maxarea = maxIslandSize;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                int area = getMergedArea(grid,i,j,n,island_size);
                maxarea = max(maxarea,area);
            }
        }
    }

    return maxarea;
}

int main()
{
    vector<vector<int>> grid = {
        {1,1,0,1},
        {0,0,0,0},
        {0,0,0,0},
        {1,1,0,0}
    };
    int output = makeLargestIsland(grid);
    cout<<"Largest island after flipping at-most 1 zero: "<<output;
    return 0;
}
