#include<bits/stdc++.h>
#include<set>
using namespace std;

// find the longest consecutive sequence (not sub-array|in any order) 

int main(int argc, char const *argv[])
{
    vector<int> arr = {9,5,4,9,10,10,6};
    int n = arr.size();

    set<int> temp;

    for(auto it:arr){
        temp.insert(it);
    }

    int sequence = 1;
    int max_seq = 1;
    int track = 0;
    int prev;
    for(auto it:temp){
        if(track != 0){
            if(it == prev+1){
                sequence++;
            }
            else{
                max_seq = max(sequence,max_seq);
                sequence = 1;
            }  
        }
        prev = it;
        track++;
    }
    max_seq = max(sequence,max_seq);

    cout<<"Longest sequence length is: "<<max_seq;

    return 0;
}
