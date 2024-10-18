#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string s, int i, int j, bool one_allowance){
    if(i==j){
        return true;
    }

    if(i-j==1 && s[i]==s[j]){
        return true;
    }

    if(s[i] != s[j]){
        if(one_allowance)
            return isPalindrom(s,i+1,j,false) || isPalindrom(s,i,j-1,false);
        return false;
    }
    
    return isPalindrom(s,i+1,j-1,one_allowance);
}

int main(int argc, char const *argv[])
{
    /* code */
    string s = "abcda";
    cout<<isPalindrom(s,0,s.size()-1,true);
    return 0;
}
