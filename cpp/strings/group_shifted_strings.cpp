#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupStrings(vector<string>& strings){
    unordered_map<string, vector<string>> mpp;

    for(auto it: strings){
        int base_diff = it[0] - 'a';
        string temp = it;
        for(int i=0;i<temp.size();i++){
            char ch = temp[i] - base_diff;
            if(ch < 'a') ch += 26;   // edge case
            temp[i] = ch;
        }
        mpp[temp].push_back(it);
    }
    vector<vector<string>> output;
    for(auto it: mpp){
        output.push_back(it.second);
    }
    return output;
}

int main()
{
    vector<string> strings = {"abc","bcd","acef","xyz","az","ba","a","z"};
    
    vector<vector<string>> output = groupStrings(strings);
    for(auto it: output){
        for(auto its: it){
            cout<<its<<" ";
        }
        cout<<endl;
    }
    return 0;
}
