#include<bits/stdc++.h>
using namespace std;

int longest_subs(string s){
    string vowel = "aeiou";
    int prefix = 0; //each bit will have either 0 or 1 since we'll be exor-ing index of vowel string
    //only 5 bits will be used of this int to set reset 5 vowel positions 
    int result = 0;
    unordered_map<int,int> prefixBitMap {{0,-1}}; //stores the bitmask of the prefixes

    for(int i=0;i<s.size();i++){
        size_t found = vowel.find(s[i]); //check if vowel
        
        if(found != string::npos){
            prefix ^= 1<<found; // get the bitmask by exoring the prefix
                            // 1<<found gets the bit representation 
                            // of the index of vowel in vowel string
        }

        if(prefixBitMap.find(prefix) == prefixBitMap.end()){ //if prefix not found in prefix map
            prefixBitMap[prefix] = i;                       // add it to the map
        }
        result = max(result, i-prefixBitMap[prefix]);   // length of last prefix that matches the 
    }                                                   // current pattern of bits
    return result;
}

int main(int argc, char const *argv[])
{
    string s = "gggaegga";
    string s = "aeaxxoo";
    int n = longest_subs(s);
    cout<<"Longest substring with even number of vowels is of length: "<<n;
    return 0;
}
