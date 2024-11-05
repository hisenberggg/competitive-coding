#include<bits/stdc++.h>
using namespace std;

vector<int> exclusiveTime(int n, vector<string>& logs){

    vector<vector<int>> parsedLogs;
    for(auto log: logs){
        stringstream ss(log);
        string part;

        vector<int> temp;
        while(getline(ss,part,':')){
            if(part == "start"){
                temp.push_back(0);
            }
            else if(part == "end"){
                temp.push_back(1);
            }
            else{
                int num = stoi(part);
                temp.push_back(num);
            }
        }
        parsedLogs.push_back(temp);
    }

    stack<vector<int>> stk;
    vector<int> output(n,0);
    int last_time;
    for(auto it:parsedLogs){
        vector<int> top;
        if(!stk.empty()){
            top = stk.top();
        }
        if(it[1]==0){    // start
            if(!stk.empty()){
                output[top[0]] += it[2] - last_time;
            }
            stk.push(it);
            last_time = it[2];
        }
        else{            // end
            stk.pop();
            output[top[0]] += it[2] - last_time + 1;
            last_time = it[2] + 1;
        }
    }

    return output;
}

int main()
{
    int n = 2;
    vector<string> logs = {
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"
    };

    vector<int> output = exclusiveTime(n, logs);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}
