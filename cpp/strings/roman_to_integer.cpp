#include<bits/stdc++.h>
using namespace std;

int get_roman_to_integer(string s){
    unordered_map<char,int> mpp = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int n = s.size();
    int total = 0;
    for(int i=0;i<n;i++){
        if(i!=0 && mpp[s[i-1]]<mpp[s[i]]){
            total += (mpp[s[i]] - 2*mpp[s[i-1]]);
        }
        else{
            total += mpp[s[i]];
        }
    }
    return total;
}

int main(){
    string s = "XI";
    int output = get_roman_to_integer(s);
    cout<<"Roman to integer: "<<s<<" -> "<<output;
}
