#include<bits/stdc++.h>
using namespace std;

int subarray_count(vector<int> arr, int k){
    unordered_map<int, int> prefix_count = {{0,1}};
    int sum = 0;
    int subarray_count = 0;

    for(auto it:arr){
        sum += it;
        subarray_count += prefix_count[sum-k];
        prefix_count[sum]++;
    }

    return subarray_count;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,-1,0};
    int k = 3;
    
    cout<<"Number of subarrays with sum k is: "<<subarray_count(arr, k);
    return 0;
}
