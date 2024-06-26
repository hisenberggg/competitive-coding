#include<bits/stdc++.h>
using namespace std;

void get_sentences(string s, vector<string> &dictionary, vector<string> &output, string sentence, int i, int j){

    if(i==s.size()){
        output.push_back(sentence);
        return;
    }
    if(j>s.size() || i>s.size()) return;

    string temp = s.substr(i,j);
    // cout<<i<<" "<<j<<" "<<temp<<endl;
    if(find(dictionary.begin(),dictionary.end(),temp) != dictionary.end()){
        // cout<<"found "<<temp<<endl;

        get_sentences(s,dictionary,output,sentence+temp+" ",i+j,1);

    }
    get_sentences(s,dictionary,output,sentence,i,j+1);
}

int main(){
    string s = "godisnowherenowhere";
    vector<string> dictionary = {"god", "is", "now", "no", "where", "here"};

    vector<string> output;
    string sentence = "";

    get_sentences(s,dictionary,output,sentence,0,1);

    for(auto it:output){
        cout<<it<<endl;
    }

    return 0;
}