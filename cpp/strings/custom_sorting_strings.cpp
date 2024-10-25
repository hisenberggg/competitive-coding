#include<bits/stdc++.h>
using namespace std;

string customSortString(string s, string order){
    unordered_map<char,int> mpp;
    string output;

    for(auto it:s){
        mpp[it]++;
    }

    for(auto it:order){
        while(mpp[it]){
            output += it;
            mpp[it]--;
        }
    }
    for(auto it:mpp){
        while(mpp[it.first]>0){
            output += it.first;
            mpp[it.first]--;
        }
    }

    return output;
}

int main()
{
    string s = "abcd";
    string order = "cba";

    cout<<"Custom sorted string: "<<customSortString(s, order);
    return 0;
}
