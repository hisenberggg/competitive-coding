#include<bits/stdc++.h>
using namespace std;

vector<string> getCombinitions(string digits){
    vector<string> output;
    if(digits.size()==0) 
        return output;
    
    unordered_map<char,vector<string>> mpp = {
        {'2',{"a","b","c"}},
        {'3',{"d","e","f"}},
        {'4',{"g","h","i"}},
        {'5',{"j","k","l"}},
        {'6',{"m","n","o"}},
        {'7',{"p","q","r","s"}},
        {'8',{"t","u","v"}},
        {'9',{"w","x","y","z"}}
    };
    char ch = digits[0];
    output.insert(output.end(),mpp[ch].begin(),mpp[ch].end());

    for(int i=1;i<digits.size();i++){
        ch = digits[i];
        int opsize = output.size();
        for(int j=0;j<opsize;j++){
            string first = output[j];
            for(int k=0;k<mpp[ch].size();k++){
                if(first==output[j]){
                    output[j] += mpp[ch][k];
                }
                else
                    output.push_back(first+mpp[ch][k]);
            }
        }
    }

    return output;
}

int main()
{
    string digits = "234";
    vector<string> output = getCombinitions(digits);
    for(auto it:output){
        cout<<it<<endl;
    }
    return 0;
}
