#include<bits/stdc++.h>
using namespace std;

int makePartition(int lowerbound, int upperbound, vector<int>& arr){
    int pivot = arr[lowerbound];  
    int l = lowerbound, u = upperbound;

    while(l<u){ // let the smaller element pass
        while(arr[l]<=pivot && l<u){
            l++;
        }

        while(arr[u]>pivot){ // let the greater elements pass
            u--;
        }

        if(l<u){ // if not crossed, them swap
            swap(arr[l],arr[u]);
        }
    }
    arr[lowerbound] = arr[u];
    arr[u] = pivot;           // put pivot in its right position

    return u;
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
            return arr[partition]; // if partition == nth 
        }
    }
}

int kth_largest_heap(vector<int> arr, int k){
    int n = arr.size();
    
    if(n-k > n/2){       // check if min elements to pop 
        int to_pop = k-1;             // number of elements to pop from max heap
        priority_queue<int> max_heap; // max element at the top

        for(auto it:arr){
            max_heap.push(it);
        }

        for(int i=0;i<to_pop;i++){
            max_heap.pop();
        }

        return max_heap.top();
    }
    else{
        int to_pop = n-k;
        priority_queue<int, vector<int>, greater<int>> min_heap; // min element at the top: min_heap

        for(auto it:arr){
            min_heap.push(it);
        }

        for(int i=0;i<to_pop;i++){
            min_heap.pop();
        }

        return min_heap.top();
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,2,5,6,4,1};
    int nth_largest = 5;

    // >> find the nth largest using quick select algo
    // int nth = arr.size() - nth_largest;
    // cout<<nth_largest<<"th largest element is: "<<quickSelect(0,arr.size()-1,arr,nth);

    // >> find the nth largest using heap 
    cout<<nth_largest<<"th largest element is: "<<kth_largest_heap(arr,nth_largest);
    
    return 0;
}
