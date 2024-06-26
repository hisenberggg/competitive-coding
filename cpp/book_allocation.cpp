#include<bits/stdc++.h>
using namespace std;

bool is_allocation_possible(int mid, vector<int> &time, int m, int n){
    int allocation_count = 1;
    int count = 0;
    for(int i=0;i<m;i++){
        if(count+time[i]<=mid){
            count += time[i];
        }
        else{
            allocation_count++;
            count = time[i];
        }
    }
    if(allocation_count>n)
        return false;
    else    
        return true;
}

int get_minimum_maxtime(vector<int> &time, int m, int n){
    if(n>m) return -1;

    int low = time[0];
    int high = 0;
    for(int i=0;i<m;i++){
        if(i!=0 && time[i]>low) 
            low = time[i];
        high += time[i];
    }


    while(low<=high){
        int mid = (low+high)/2;
        if(is_allocation_possible(mid,time,m,n)){
            int res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> time = {2, 7, 9, 10, 5, 4};
    int m = time.size();
    int n = 4;

    int output = get_minimum_maxtime(time,m,n);
    cout<<"Minimum of the maximum is: "<<output;
    return 0;
}