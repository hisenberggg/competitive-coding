#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> arr){
    int left = 0, right = arr.size()-1;
    while(left<right){
        int mid = (left+right)/2;
        if(arr[mid]<arr[mid+1]){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }

    return arr[left];
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,1,4,5};
    cout<<findPeak(arr);
    return 0;
}
