#include<bits/stdc++.h>
using namespace std;

void get_unique_subsets(vector<int> &arr, vector<vector<int>> &output, int n, int index, vector<int> temp){
        
    output.push_back(temp);
    for(int i=index;i<n;i++){
        if(i!=index && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        get_unique_subsets(arr,output,n,i+1,temp);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr = {1,1,3};

    vector<vector<int>> output;
    vector<int> temp;
    get_unique_subsets(arr,output,arr.size(),0,temp);
    for(auto it:output){
        cout<<endl;
        for(auto its:it){
            cout<<its<<" ";
        }
    }
    return 0;
}
