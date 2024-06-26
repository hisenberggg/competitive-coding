#include<bits/stdc++.h>
using namespace std;

int get_max_ones(vector<int> &arr, int n, int k){
    int max_streak = 0;
    int start = 0;
    int zero_used = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            max_streak = max(max_streak,i-start+1);
        }
        else{
            if(zero_used<k){
                zero_used++;
            }
            else{
                while(start<n-1 && arr[start]!=0){
                    start++;
                }
                start++;
            }
            max_streak = max(max_streak,i-start+1);
        }
        // cout<<"- i: "<<i<<", start: "<<start<<", max streak: "<<max_streak<<endl;
    }
    return max_streak;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0} ;
    int n = arr.size();
    int k = 3;

    int ans = get_max_ones(arr,n,k);
    cout<<"Max consecutive 1s possible are: "<<ans<<endl;
    return 0;
}
