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

int quickselect(vector<int> &arr, int lowerbound, int upperbound, int nth){
    int ans;
    if(lowerbound<=upperbound){
        int p = partition(arr,lowerbound,upperbound);

        if(p == nth) 
            return arr[p];

        if(nth<p){
            return quickselect(arr,lowerbound,p-1,nth);
        }
        else{
            return quickselect(arr,p+1,upperbound,nth);
        }   
    }
}

// 2 3 4 5 8 10 12 20
int main(){
    vector<int> arr = {12,5,3,20,4,8,10,2};
    int n = arr.size();
    int nlargest = 1;
    int nth = n-nlargest;

    int ans = quickselect(arr,0,n-1,nth);

    cout<<ans;
    
    return 0;
}
