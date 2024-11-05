#include<bits/stdc++.h>
using namespace std;

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]

bool isPresent(string s, string word){ // check if word is present from the start
    for(int i=0,j=0;i<word.size();i++,j++){
        if(s[j] != word[i]) return false;
    }       
    return true;
}

void getSentences(string s, vector<string> wordDict, vector<string>& output, string op_string){
    if(s.size()==0){
        output.push_back(op_string.substr(1));
        return;
    }

    for(int i=0;i<wordDict.size();i++){
        if(isPresent(s,wordDict[i])){
            string not_take_string = op_string; // store a copy for backtracking
            // take 
            op_string += " " + wordDict[i];
            string take_word = wordDict[i];
            int take_word_size = take_word.size();
            getSentences(s.substr(take_word_size),wordDict,output,op_string); // take the string 

            op_string = not_take_string; // back track
        }

    }
}

vector<string> wordBreak(string s, vector<string> wordDict){
    vector<string> output;
    getSentences(s,wordDict,output,"");
    return output;
}

int main()
{
    // string s = "catsanddog";
    // vector<string> wordDict = {
    //         "cat",
    //         "cats",
    //         "and",
    //         "sand",
    //         "dog"
    //     };
    string s = "pineapplepenapple";
    vector<string> wordDict = {
            "apple","pen","applepen","pine","pineapple"
        };
    vector<string> valid_sent = wordBreak(s,wordDict);
    for(auto sent: valid_sent){
        cout<<sent<<endl;
    }
    return 0;
}
