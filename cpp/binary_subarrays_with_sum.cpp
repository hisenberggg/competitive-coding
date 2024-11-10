#include<bits/stdc++.h>
using namespace std;

void powerset(vector<int>& nums, int goal, int sum, int ind, int& count){
	if(ind == nums.size()){
		if(sum == goal) count++;
        return;
    }
		
    powerset(nums,goal,sum + nums[ind],ind+1,count);    
    powerset(nums,goal,sum,ind+1,count);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    
    vector<vector<int>> output;
    int sum = 0;
    int ind = 0;
    int count = 0;
    powerset(nums,goal,sum,ind, count);
    cout<<count;
    return 0;
}
