#include<bits/stdc++.h>
using namespace std;

// find minimun number of operations to convert word1 to word2
// operations: insert, delete, replace 

int minDistance(string word1, string word2, int i, int j){
    // if either is empty or done processing - return the remaining of other (insert/delete)
    if(i==word1.size() || j==word2.size()){        
        return max(word1.size()-i, word2.size()-j); // one of them would result in 0
    }
    
    if(word1[i] == word2[j]){
        // if the char at i & j are same, move ahead
        return 0 + minDistance(word1,word2, i+1, j+1); 
    }
    else{
        // if not same then we can do 3 operations to handle the mismatch
        // in the end choose min path 

        // if we choose to insert, assume it is inserted behind i and move j ahead 
        int insertop = 1 + minDistance(word1,word2,i,j+1);

        // if delete, assume i is deleted and move it ahead 
        int deleteop = 1 + minDistance(word1,word2,i+1,j);

        // if replace, char at j is repalced with char at j so both move ahead 
        int replaceop = 1 + minDistance(word1,word2,i+1,j+1);

        // in the end, choose the path that costed minimum 
        return min(insertop, min(deleteop,replaceop));
    }
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    int output =  minDistance(word1,word2,0,0);
    cout<<"Min operations: "<<output;
    return 0;
}
