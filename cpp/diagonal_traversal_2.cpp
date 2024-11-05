#include<bits/stdc++.h>
using namespace std;

vector<int> get_diagonal(vector<vector<int>> nums){
    int row = nums.size();

    vector<vector<int>> arr;
    for(int i=0;i<row;i++){
        int col = nums[i].size();
        for(int j=0;j<col;j++){
            arr.push_back({i+j, j, nums[i][j]});
        }
    }

    sort(arr.begin(),arr.end());
    vector<int> output;
    for(auto it:arr){
        output.push_back(it[2]);
    }

    return output;
}

int main()
{
    vector<vector<int>> matrix = {
        {1 ,2 ,3 ,4 ,5 },
        {1 ,2 ,3 },
        {1 ,2 ,3 ,4 }
    }; 

    vector<int> output = get_diagonal(matrix);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}
