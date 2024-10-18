#include<bits/stdc++.h>
using namespace std;

int makePartition(int lowerbound, int upperbound, vector<int>& arr){
    int pivot = arr[lowerbound];  
    int l = lowerbound, u = upperbound;

    while(l<u){
        while(arr[l]<=pivot && l<u){
            l++;
        }

        while(arr[u]>pivot){
            u--;
        }

        if(l<u){
            swap(arr[l],arr[u]);
        }
    }
    arr[lowerbound] = arr[u];
    arr[u] = pivot;

    return u;
}

void quicksort(int lowerbound, int upperbound, vector<int>& arr){

    if(lowerbound<upperbound){
        int partition = makePartition(lowerbound,upperbound,arr);

        quicksort(lowerbound,partition-1,arr);
        quicksort(partition+1,upperbound,arr);
    }
}

int quickSelect(int lowerbound, int upperbound,vector<int>& arr, int nth){
    if(lowerbound<upperbound){
        int partition = makePartition(lowerbound,upperbound,arr);

        if(partition>nth){
            return quickSelect(lowerbound,partition-1,arr,nth);
        }
        else if(partition<nth){
            return quickSelect(partition+1,upperbound,arr,nth);
        }
        else{
            return arr[partition];
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,2,5,6,4,1};

    // quicksort(0,arr.size()-1,arr);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }

    // find the nth largest
    int nth_largest = 2;
    int nth = arr.size() - nth_largest;

    cout<<nth_largest<<"th largest element is: "<<quickSelect(0,arr.size()-1,arr,nth);
    
    return 0;
}
