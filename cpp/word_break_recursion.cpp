#include<bits/stdc++.h>
#include<string>

using namespace std;

bool is_word_break(string s, vector<string> word_dict){
    if(s.size()==0) return true;

    for(int i=0;i<word_dict.size();i++){
        size_t loc = s.find(word_dict[i]); 
        if(loc != string::npos){
            cout<<" word found: '"<<word_dict[i]<<"' at location: "<<loc<<endl;
            s = s.substr(0,loc) + s.substr(loc+word_dict[i].size(),s.size());
            cout<<"string after: "<<s<<endl;
            return true && is_word_break(s,word_dict);
        }
    }
    return false;
}

int main(){
    string s = "leetcodeleettestcodecode";
    vector<string> wordDict = {"leet","code","test"};

    bool is_break = is_word_break(s,wordDict);
    string result = is_break?"word broken":"word can't be broken";
    cout<<"result: "<<result;

}