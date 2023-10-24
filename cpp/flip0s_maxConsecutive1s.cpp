#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1}, zeroPos;
    int n = arr.size(), m = 2;
    int wl = 0, wr = 0, zeroCount = 0, bestWindow = 0, bestL = 0;

    while(wr<=n){
        if(zeroCount <= m){
            if(arr[wr] == 0) zeroCount++;
            wr++;
        }
        if(zeroCount>m){
            if(arr[wl] == 0) zeroCount--;
            wl++;
        }
        if(wr-wl > bestWindow && zeroCount <= m){
            bestWindow = wr-wl;
            bestL = wl;
        }
    }
    for(int ind = 0; ind < bestWindow;ind++){
        if(arr[ind+bestL] == 0) zeroPos.push_back(ind+bestL);
    }

    for(auto i: zeroPos) cout<<i<<endl;
    return 0;
}