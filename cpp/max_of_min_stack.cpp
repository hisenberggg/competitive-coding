#include<bits/stdc++.h>
using namespace std;

vector<int> get_max_of_min(vector<int> &a, int n){
    vector<int> left;
    vector<int> right;
    // left and right vectors are used to know the range of each element 
    for(int i=0;i<n;i++){
        left.push_back(-1);
        right.push_back(n);
    }

    stack<int> stk;
    stk.push(0);
    // find the left minimum of each element 
    for(int i=1;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i])
            stk.pop();

        if(!stk.empty())
            left[i] = stk.top();
        
        stk.push(i);
    }

    while(!stk.empty())
        stk.pop();

    stk.push(n-1);
    // find the right minimum of each element 
    for(int i=n-2;i>=0;i--){
        while(!stk.empty() && a[stk.top()]>=a[i])
            stk.pop();

        if(!stk.empty())
            right[i] = stk.top();
        
        stk.push(i);
    }

    vector<int> ans;
    for(int i=0;i<=n;i++){
        ans.push_back(INT_MIN);
    }

    // calculate range of each element 
    // and it would be a good candidate for the window size equal to its range 
    for(int i=0;i<n;i++){
        int range = right[i] - left[i] - 1;
        ans[range] = max(ans[range],a[i]);
    }

    // if there is no max for certain window size 
    // it would be same as window size greater than them 
    for(int i=n-1;i>=1;i--){
        ans[i] = max(ans[i],ans[i+1]);
    }

    return ans;
}

int main(){
    vector<int> arr = {45, -2, 42, 5, -11};
    int n = arr.size();

    vector<int> output = get_max_of_min(arr,n);

    for(int i=1;i<=n;i++){
        cout<<output[i]<<" ";
    }
    return 0;
}