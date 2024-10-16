#include<bits/stdc++.h>
using namespace std;

int getMaxSubseq(vector<int> &arr, int ind, int n, int prev){
    if(ind==n){
        return 0;
    }
    int notTake = 0 + getMaxSubseq(arr,ind+1,n,arr[ind]);

    int take = 0;
    if(prev == -1 || arr[ind]>arr[prev]){
        take = 1 + getMaxSubseq(arr,ind+1,n,arr[ind]);
    }
    return max(take,notTake);

}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,4,5,7,3,2,6,7,8,4};
    int n = arr.size();
    int prev = -1;
    int start = 0;
    cout<<"Max increasing subsequence: "<<getMaxSubseq(arr,start,n,prev);
    return 0;
}
