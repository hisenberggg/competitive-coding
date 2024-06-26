#include<bits/stdc++.h>
using namespace std;

// print all the substrings that are plaindroms 

bool is_palindrom(string s){
    int i = 0, j = s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}

void get_palindrom_strings(string s, vector<vector<string>> &output, int ind, vector<string> ds){

}

int main(){
    
    string s = "a";
    vector<string> ds;
    vector<vector<string>> output;

    get_palindrom_strings(s,output,0,ds);
    cout<<"output: "<<endl;
    for(auto it:output){
        for(auto its:it){
            cout<<its<<", ";
        }
        cout<<endl;
    }
    return 0;
   
}