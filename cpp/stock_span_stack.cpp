#include<bits/stdc++.h>
using namespace std;

vector<int> get_stock_span(vector<int> &prices){
    int n = prices.size();
    stack<int> stk;
    vector<int> output;

    stk.push(0);
    output.push_back(1);
    for(int i=1;i<n;i++){
        while(!stk.empty() && prices[stk.top()]<prices[i]){
            stk.pop();
        }
        if(!stk.empty()){
            output.push_back(i-stk.top());
        }
        else{
            output.push_back(i+1);
        }
        stk.push(i);
    }

    return output;
}

int main(){
    // vector<int> prices = {2,1,2,4};
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> output = get_stock_span(prices);
    for(auto it:output){
        cout<<it<<" ";
    }
    return 0;
}