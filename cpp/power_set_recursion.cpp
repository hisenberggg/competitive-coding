#include<bits/stdc++.h>
using namespace std;

void get_powerset(vector<vector<int>>& op, vector<int> a,vector<int> se, int i, int n){
    if(i == n){
        cout<<se.size()<<endl;
        op.push_back(se);
        return;
    }
    
    se.push_back(a[i]);
    get_powerset(op,a,se,i+1,n);
    se.pop_back();
    get_powerset(op,a,se,i+1,n);
    
}

int main(int argc, char const *argv[])
{
    vector<int> a = {1,2,3};
    int n = a.size();
    vector<vector<int>> op; //store the output
    vector<int> se;
    // get all subsequences
    get_powerset(op,a,se,0,n);

// print the output
    for(auto p:op){
        for(auto q:p){
            cout<<q<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
