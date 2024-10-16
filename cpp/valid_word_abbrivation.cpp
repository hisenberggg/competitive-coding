#include<bits/stdc++.h>
using namespace std;

bool isValidWord(string word, string abbr){
    int word_len = word.size();
    int abbr_len = abbr.size();
    int word_tracker = 0, abbr_tracker = 0, number = 0;

    for(;word_tracker<word_len && abbr_tracker<abbr_len; abbr_tracker++){
        char ch = abbr[abbr_tracker];
        if(isdigit(ch)){
            if(ch=='0' && number==0) 
                return false;
            number = number * 10 + (ch-'0');
        }
        else{
            word_tracker += number;
            number = 0;
            if(word_tracker>word_len && word[word_tracker] != abbr[abbr_tracker]) 
                return false;
            word_tracker++;
        }
    }

    return (word_tracker == word_len) && (abbr_tracker+number == word_len);
}


int main(int argc, char const *argv[])
{
    /* code */
    string word = "internationalization";
    string abbr = "i12iz4n";

    cout<<isValidWord(word,abbr);
    return 0;
}
