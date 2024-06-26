#include<bits/stdc++.h>
using namespace std;

// return the range of index in which the target number ranges 

vector<int> brute_force(vector<int> &arr, int target, int n){
    vector<int> output;
    int flag = false;

    for(int i=0;i<n;i++){
        if(arr[i]==target && !flag){
            output.push_back(i);
            flag = true;
        }
        if(flag && arr[i] != target){
            output.push_back(i-1);
            break;
        }
    }
    return output;
}

vector<int> binary_search(vector<int> &arr, int target, int n){
    // time complexity: (log n) + #occ
    int low = 0;
    int high = n-1;
    int mid, left, right;

    while(low<=high){
        mid = (high+low)/2;
        // cout<<"mid: "<<mid<<" "<<arr[mid]<<endl;
        if(arr[mid] == target){
            left = mid;
            right = mid;
            while(left>=0 && arr[left] == target){
                left--;
            }
            left++;
            while(right<n && arr[right] == target){
                right++;
            }
            right--;
            break;
        }
        else if(arr[mid]<target){
            low = mid + 1;
        }
        else{
            high = mid - 1; 
        }
    }
    // cout<<"mid: "<<left<<" "<<right<<endl;

    return {left,right};
}


int main(){
    vector<int> arr = {1,2,3,3,3,4,4,4,4,5,6,7};
    int target = 4;
    int n = arr.size();
    // vector<int> output = brute_force(arr,target,n);
    vector<int> output = binary_search(arr,target,n);

    cout<<"target found in range: ";
    for(auto it:output)
        cout<<it<<" ";
    return 0;
}