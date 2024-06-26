#include<bits/stdc++.h>
using namespace std;

// find element that appears only once 

int main(){
    vector<int> arr = {10, 10, 14, 16, 16, 25, 25, 28, 28, 36, 36, 44, 44};
    int n = arr.size();

    if(n==1) cout<<"Single element is: "<<arr[0];
    if(arr[0] != arr[1]) cout<<"Single element is: "<<arr[0];
    if(arr[n-1] != arr[n-2]) cout<<"Single element is: "<<arr[n-1];

    int low = 1;
    int high = n-2;
    int mid;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            cout<<"Single element is: "<<arr[mid];
        }
        if(mid%2==1 && arr[mid]==arr[mid-1] || mid%2==0 && arr[mid]==arr[mid+1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return 0;
}