#include<bits/stdc++.h>
using namespace std;

string get_reverse(string str){
    int n = str.size();
    string temp = "";
    stack<string> stk;
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            if(temp == "") continue;
            stk.push(temp);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    if(temp != ""){
        stk.push(temp);
    }

    string output = "";
    while(!stk.empty()){
        cout<<stk.top()<<endl;
        output += stk.top() + " ";
        stk.pop();
    }

    int new_n = output.size();
    output = output.substr(0,new_n-1);

    return output;
}

int main(){
    string s = "   m rs   x       JmkL       ";
    string output = get_reverse(s);
    cout<<"Reversed string is: "<<output;
    return 0;
}