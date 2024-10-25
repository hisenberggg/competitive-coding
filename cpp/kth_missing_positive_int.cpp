#include<bits/stdc++.h>
using namespace std;

int kth_missing(vector<int> arr, int k){
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = (low + high) / 2;
        int missing_count = arr[mid] - (mid + 1);
        if(missing_count >= k){
            high = mid - 1;
        }
        else{
            low  = mid + 1;
        }
    }
    
    return high + k + 1;
}

int main()
{
    vector<int> arr = {3,11};
    int k = 2;
    cout<<kth_missing(arr,k);
    return 0;
}
