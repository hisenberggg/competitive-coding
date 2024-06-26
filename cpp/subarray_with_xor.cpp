#include<bits/stdc++.h>
using namespace std;

// count the number of subarrays with bitwise xor 
// of all elements of that subarray equals to b 

int brute_force(vector<int> arr, int n, int b){
    int count = 0;
    for(int i=0;i<n;i++){
        int xor_sum = 0;    
        for(int j=i;j<n;j++){
            xor_sum ^= arr[j];
            cout<<"xorsum from "<<i<<" -> "<<j<<" is: "<<xor_sum<<endl;
            if(xor_sum == b){
                cout<<"\t* xor sum equal to "<<b<<": "<<xor_sum<<endl;
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,3,3};
    int n = arr.size();
    int b = 3;

    int count = brute_force(arr,n,b);

    cout<<"count: "<<count;
}