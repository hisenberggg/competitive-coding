#include<bits/stdc++.h>
using namespace std;

vector<int> get_next_greater(vector<int> &arr, int n){
    vector<int> nge(n,-1);
    stack<int> stk;

    for(int i=2*n-1;i>=n-1;i--){
        while(!stk.empty()){
            if(stk.top()>arr[i%n]){
                nge[i%n] = stk.top();
                stk.push(arr[i%n]);
                break;
            }
            else{
                stk.pop();
            }
        }  
        if(stk.empty())
            stk.push(arr[i%n]);
    }
        
    return nge;
}

int main(){
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    int n = arr.size();
    for(auto it:arr)
        cout<<it<<" ";
    cout<<endl;

    vector<int> output = get_next_greater(arr,n);

    for(auto it:output)
        cout<<it<<" ";
    cout<<endl;


    return 0;
}