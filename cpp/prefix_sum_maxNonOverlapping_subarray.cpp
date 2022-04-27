#include<bits/stdc++.h>
using namespace std;

// pefix sum: replace each element with the sum of all element till that max_element
// eg : 1 2 3 4 -> 1 3 6 10
// store prefix sums in set..use set because if the sum repeats then we just take the 1st occurance
// problem stmt: find the number of consecutive subarray with sum as target
// if (sum till index 5 - sum till index 3) = target
// i.e. sum of 4th and 5th = target

// (sum till index 5 - target) = sum till index 3
// so we keep on pushing previous sums in set and check if (current index sum - target) is present in the set


int nonOverlappingsubarr(vector<int> nums, int target){
    set<int> st;
    int ps = 0, count = 0;
    st.insert(0);
    for(int i = 0; i<nums.size(); i++){
        ps += nums[i];
        if(st.find(ps-target) != st.end()){
            count++;
            st.clear();
            ps = 0;
        }
        st.insert(ps);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {-1, 3, 5, 1, 4, 2, -9}; 
    int target = 6;
    cout<<"Max number of non overlapping subarray: "<< nonOverlappingsubarr(a,target)<<endl;

    return 0;
}
