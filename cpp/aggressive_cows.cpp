#include<bits/stdc++.h>
using namespace std;

int get_cows(vector<int> &stalls, int n, int k, int m){
    int curr_cows = 1;
    int prev = stalls[0];
    for(int i=1;i<n;i++){
        if(curr_cows==k) return curr_cows;
        if(stalls[i]-prev>=m){
            prev = stalls[i];
            curr_cows++;
        }
    }
    return curr_cows;
}

int get_max_distance(vector<int> &stalls, int n, int k){
    int low = 1;
    int high = stalls[n-1];
    int maxi = INT_MIN;
    while(low<=high){
        int mid = (low+high)/2;
        int cows = get_cows(stalls,n,k,mid);
        if(cows==k){
            maxi = max(mid,maxi);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return maxi;
}

int main(){
    // vector<int> stalls = {0, 3, 4, 7, 10, 9};
    vector<int> stalls = {87, 93, 51, 81, 68, 99, 59};
    int k = 4;
    int n = stalls.size();

    sort(stalls.begin(),stalls.end());

    int output = get_max_distance(stalls,n,k);
    cout<<"Maximum of the minimum distance between stalls can be: "<<output<<endl;

    return 0;
}