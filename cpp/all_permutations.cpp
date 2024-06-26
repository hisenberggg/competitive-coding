#include<bits/stdc++.h>
using namespace std;

void get_all_permutations(string s, vector<string> &output, int index){
    if(index == s.size()){
        output.push_back(s);
        return;
    }

    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        get_all_permutations(s,output,index+1);
        swap(s[index],s[i]);
    }
}

int main(){
    string s = "abc";

    vector<string> output;
    get_all_permutations(s,output,0); 

    cout<<"All permutations: "<<endl;
    for(auto it:output){
        cout<<it<<endl;
    }
    return 0;
}