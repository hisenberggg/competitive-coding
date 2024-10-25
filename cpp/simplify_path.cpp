#include<bits/stdc++.h>
using namespace std;

string simplify(string path){
    stack<string> stk;
    string dir = "";
    bool skip_next = false;

    for(int i = 0;i<path.size();i++){
        if(path[i] == '/'){

            if(dir == "." || dir == ""){
                dir = "";
            }
            else if(dir == ".."){
                dir = "";
                stk.pop();
            }
        }
        else{
            dir += path[i];
        }
    }
    string output = "";
    while(!stk.empty()){
        // output += "/" + stk.top();
        // stk.pop();
        cout<<stk.top();
        stk.pop();
    }
    return output;
}

int main(int argc, char const *argv[])
{
    string s = "/home/user/Documents/../Pictures";
    cout<<"Simplified string is: "<<simplify(s);
    return 0;
}
