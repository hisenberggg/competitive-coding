#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int>& stk, vector<int> adj[], vector<bool>& visited){
    visited[node] = true;
    for(auto it:adj[node]){
        if(!visited[it])
            dfs(it,stk,adj,visited);
    }

    stk.push(node);
}

vector<int> getTopoSort(vector<int> adj[], int n){
    vector<bool> visited(n,false);
    stack<int> stk;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,stk,adj,visited);
        }
    }

    vector<int> output;
    while(!stk.empty()){
        output.push_back(stk.top());
        stk.pop();
    }

    return output;
}

int main()
{
    int n = 6; 
    // vector<int> adj[n] = {{1},{3,2},{4},{5,6},{5},{7},{},{}};
    vector<int> adj[n] = {{},{},{3},{1},{0,1},{0,2}};
    vector<int> topo = getTopoSort(adj,n);
    
    for(auto it:topo){
        cout<<it<<" ";
    }
    return 0;
}


