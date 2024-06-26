#include<bits/stdc++.h>
using namespace std;

// largest length of subarray whose sum is zero 

int brute_force(vector<int> &arr, int n){
    int max_size = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int sum = 0;
            for(int k=j;k<j+i;k++){
                sum += arr[k];
            }
            if(sum == 0){
                max_size = max(max_size,i);
            }
        }
    }
    return max_size;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,1,-1,4,-4};
    int n = arr.size();

    int max_size = brute_force(arr,n);
    cout<<"Largest subarray length with sum 0 is: "<< max_size;
    return 0;
}
