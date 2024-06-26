#include<bits/stdc++.h>
using namespace std;

bool is_valid(string s){
    stack<char> stk;

    for(int i=0;i<s.length();i++){
        if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
            stk.push(s[i]);
        }
        else{
            char ch;
            if(!stk.empty())
                ch = stk.top();
            else    
                return false;
            if(s[i]==']' && ch=='[' || s[i]=='}' && ch=='{' || s[i]==')' && ch=='('){   
                    stk.pop();
            }
            else{
                return false;
            }
        }
    }
    if(stk.empty())
        return true;
    else    
        return false;
}

int main(){
    string s = "}])]";

    if(is_valid(s))
        cout<<"Valid string";
    else    
        cout<<"Invalid string";

    return 0;
}