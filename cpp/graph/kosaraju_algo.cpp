#include<bits/stdc++.h>
using namespace std;

void topodfs(int node, vector<int> adj[], int visited[], stack<int> &stk){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it])
            topodfs(it,adj,visited,stk);
    }
    stk.push(node);
}

vector<int> toposort(int numnodes, vector<int> adj[]){
    stack<int> stk;
    int visited[numnodes] = {0};

    for(int i=0;i<numnodes;i++){
        if(!visited[i]){
            topodfs(i,adj,visited,stk);
        }
    }
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

void dfs(int node, vector<int> transpose[], vector<int>& temp, int visited[]){
    visited[node] = 1;
    temp.push_back(node);
    for(auto it:transpose[node]){
        if(!visited[it]){
            dfs(it,transpose,temp,visited);
        }
    }
}

vector<vector<int>> get_scc(vector<int> &toparr, vector<int> transpose[], int numnodes){
    int visited[numnodes] = {0};
    vector<vector<int>> ans;

    for(int i=0;i<numnodes;i++){
        int node = toparr[i];
        if(!visited[node]){
            vector<int> temp;
            dfs(node,transpose,temp, visited);
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<vector<int>> kosaraju(int numnodes, vector<int> adj[]){
    vector<int> topoarr = toposort(numnodes,adj);

    vector<int> transpose[numnodes];
    for(int i=0;i<numnodes;i++){
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }

    // dfs to get scc (Strongly Connected Components)
    vector<vector<int>> scc = get_scc(topoarr,transpose,numnodes);

    return scc;
}

void addedge(vector<int> adj[],int x, int y){
    adj[x].push_back(y);
}

int main(int argc, char const *argv[])
{
    int numnodes = 5;
    vector<int> adj[numnodes];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,0);
    addedge(adj,1,3);
    addedge(adj,3,4);

    vector<vector<int>> ans = kosaraju(numnodes,adj);

    cout<<"Strongly connected conponents are: "<<endl;
    for(auto it:ans){
        for(auto its:it){
            cout<<its<<" ";
        }
        cout<<endl;
    }

    return 0;
}
