#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> intervals = {
        {1,4},
        {0,2},
        {3,5}
    };
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());
    int i = 1;
    while(i<n){
        if(intervals[i-1][1] >= intervals[i][0]){
            intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
            intervals.erase(intervals.begin()+i);
            n--;
        }
        else    
            i++;
    }

    for(auto it:intervals){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}
