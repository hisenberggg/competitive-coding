#include<bits/stdc++.h>
#include<string>
using namespace std;

// number of pairs of 2 with sum as target

int two_sum(vector<int> &arr, int n, int target){
    set<int> s;
    int count  = 0;

    for(int i=0;i<n;i++){
        if(s.count(target - arr[i])){
            count++;
        }
        s.insert(arr[i]);
    }
    return count;
}

int main(){
    int target = 8;
    vector<int> arr = {2,5,4,6,1,2,3};
    int n = 6;

    cout<<"Number of pairs with sum as '"<<target<<"' is: "<<two_sum(arr,n,target);
}