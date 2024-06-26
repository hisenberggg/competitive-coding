#include<bits/stdc++.h>
using namespace std;

bool is_palindrom(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}

string get_longest_pal_substring_bruteforce(string str){
    int n = str.size();
    int maxi = INT_MIN;
    string max_str = "";
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(is_palindrom(str,i,j)){
                if(maxi<j-i+1){
                    maxi = j-i+1;
                    max_str = str.substr(i,j-i+1);
                }
            }
        }
    }
    return max_str;
}

string get_longest_pal_substring_optimal(string str){
    int n = str.size();
    int max_len = INT_MIN;
    string max_str = "";
    for(int i=0;i<n;i++){

        // for odd substrings 
        int j=i, k=i;
        while(j>=0 && k<n && str[j]==str[k]){
            if(max_len<(k-j+1)){
                max_len = k-j+1;
                max_str = str.substr(j,k-j+1);
            }
            j--;k++;
        }

        // for even substrings 
        j=i;
        k=i+1;
        while(j>=0 && k<n && str[j]==str[k]){
            if(max_len<(k-j+1)){
                max_len = k-j+1;
                max_str = str.substr(j,k-j+1);
            }
            j--;k++;
        }
    }

    return max_str;
}


int main(){
    string s = "aaaabbaa";
    // string output = get_longest_pal_substring_bruteforce(s);
    string output = get_longest_pal_substring_optimal(s);

    cout<<"Longest palindromic substring: "<<output;
    return 0;
}
