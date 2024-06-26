#include<bits/stdc++.h>
using namespace std;


int main(){
    
    vector<string> vec = {"CC", "A", "DD", "BB", "B", "ZZZ", "C","AA", "AAAAA","BC", "AAA"};
    vector<vector<string>> bucket(10);
    
    for(auto it:vec){
        bucket[it.size()-1].push_back(it);
    }

    

    for(int i=0;i<10;i++){
        if(!bucket[i].empty())
            sort(bucket[i].begin(), bucket[i].end());
    }

    vector<string> ans;
    for(int i=0;i<10;i++){
        for(int j=0;j<bucket[i].size();j++){
            cout<<bucket[i][j]<<" ";
            ans.push_back(bucket[i][j]);
        }
        cout<<endl;
    }

    for(auto it:ans){
        cout<<it<<" ";
    }
}
