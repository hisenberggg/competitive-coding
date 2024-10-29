/* Find the subarray whose sum%k equals 0 and whose lenght is >= 2:
- Calculate prefix sum 
- store the remainder of each sum in map<sum,index> (index to check >= 2 criteria) 
- everytime check if current remainder exist in map.key 
- if present then we've add value whose mod k is 0 
- before returning check >=2 criteria. Therefore, we've found the subarray */

#include<bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k){
    int n = nums.size();
    
    if(n<2) return false; // since the subarray len should be min 2

    map<int,int> prefixMap;
    prefixMap[0] = -1;
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += nums[i];
        int rem = sum%k;

        if(prefixMap.find(rem) != prefixMap.end()){
            if(i - prefixMap[rem] >= 2){
                return true;
            }
        }
        else{
            prefixMap[rem] = i;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    cout<<"Continuous sum found? "<<(checkSubarraySum(nums,k)?"Yes":"No");
    return 0;
}
