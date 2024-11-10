#include<bits/stdc++.h>
using namespace std;

string simplify(string path){
    stack<string> stk;
    stringstream ss(path);
    string dir;

    while(getline(ss,dir,'/')){
        if(dir.size()){
            stk.push(dir);
        }
    }

    int skipdir = 0;
    string output;
    while(!stk.empty()){
        string top = stk.top();
        stk.pop();

        if(top=="..") 
            skipdir++;
        else if(top==".") 
            continue;
        else{
            if(skipdir){
                skipdir--;
                continue;
            }
            output = '/' + top + output;
        } 
    }
    return output;
}

int main(int argc, char const *argv[])
{
    string s = "/home/user/Documents/../Pictures";
    // string s = "/a/./b/../../c/";
    cout<<"Simplified string is: "<<simplify(s);
    return 0;
}
