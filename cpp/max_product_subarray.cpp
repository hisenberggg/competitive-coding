#include<bits/stdc++.h>
using namespace std;

int get_max_product(vector<int> &arr){
    int pre = 1, suf = 1;
    int ans = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        pre = pre?pre:1;
        suf = suf?suf:1;
        pre *= arr[i];
        suf *= arr[n-i-1];
        ans = max({pre,suf,ans});
    }

    return ans;
}

int main() {
	// your code goes here
    vector<int> arr = {2,-3,-2,4};
    cout<<"The maximim product is: "<<get_max_product(arr);

    return 0;
}

