#include<bits/stdc++.h>
using namespace std;

vector<int> sliding_max_brute_force(vector<int> &arr, int n, int k){
    vector<int> output;
    for(int i=0;i<n-k+1;i++){
        int maxi = INT_MIN;
        for(int j=0;j<k;j++){
            maxi = max(maxi,arr[j+i]);
        }
        output.push_back(maxi);
    }

    return output;
}

vector<int> sliding_max_optimal(vector<int> &arr, int n, int k){
    deque<int> dq;
    vector<int> output;
    for(int i=0;i<n;i++){
        // first check is the current element is in the range (k)
        while(!dq.empty() && !(dq.front()>i-k && dq.front()<=i)){
            dq.pop_front();
        }

        // if back of dq is smaller then current element then pop back 
        // i.e. maintain the decreasing order in the dq 
        while(!dq.empty() && arr[i]>arr[dq.back()]){
            dq.pop_back();
        }

        // put every element in the dq 
        dq.push_back(i);

        // when 1st set of k elements is done processing then start adding to output 
        if(i>=k-1){
            output.push_back(dq.front());
        }
    }

    return output;
}

int main(){
    vector<int> arr = {3,4,-1,1,5};
    int n = arr.size();
    int k = 3;

    // vector<int> output = sliding_max_brute_force(arr,n,k);
    vector<int> output = sliding_max_optimal(arr,n,k);

    for(auto it:output){
        cout<<arr[it]<<" ";
    }

    return 0;
}