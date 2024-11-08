#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper){
    vector<vector<int>> output;
    int prev = -1;

    for(auto it:nums){
        if(it-1 == prev+1){
            output.push_back({prev+1});
        }
        else if(it > prev+1){
            output.push_back({prev+1,it-1});
        }
        prev = it;
    }
    if(upper>prev+1){
        output.push_back({prev+1,upper});
    }
    return output;
}

int main()
{
    vector<int> nums = {0,1,3,50,75};
    int lower = 0;
    int upper = 99;

    vector<vector<int>> output = findMissingRanges(nums,lower,upper);
    for(auto it:output){
        for(auto its:it){
            cout<<its<<" ";
        }
        cout<<endl;
    }
    return 0;
}
