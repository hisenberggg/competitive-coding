#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int lb, int ub){
    int no = arr[lb];
    int l = lb, u = ub;

    while(l<u){
        while(no>=arr[l] && l<u){
            l++;
        }

        while(no<arr[u]){
            u--;
        }

        if(l<u){
            swap(arr[l],arr[u]);
        }
    }
    arr[lb] = arr[u];
    arr[u] = no;

    return u;
}

void quicksort(vector<int> &arr, int lowerbound, int upperbound){
    if(lowerbound < upperbound){
        int p = partition(arr,lowerbound,upperbound);

        quicksort(arr,lowerbound,p-1);
        quicksort(arr,p+1,upperbound);
    }
}

int main()
{
    /* code */
    vector<int> arr = {12,5,3,20,4,8,10,2};
    int n = arr.size();

    quicksort(arr,0,n-1);

    for(auto it:arr){
        cout<<it<<" ";
    }

    return 0;
}
