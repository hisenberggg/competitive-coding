#include<bits/stdc++.h>
using namespace std;

// Topological sort the graph
// pre-requisite = Directed, Acyclic graph (DAG)

// write functions here 
void dfs(int node, vector<int> adj[], stack<int> &stk, int visited[]){ 
    //pass everything by reference
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,stk,visited);
        }
    }
    // after going to depth, push the node to the stack 
    stk.push(node);
}

void toposort(int numnodes, vector<int> adj[]){
    stack<int> stk;
    int visited[numnodes] = {0};

    // traverse all nodes 
    for(int i=0;i<numnodes;i++){
        if(!visited[i])
            dfs(i,adj,stk,visited); //if not visited, go the depth of that node
    }

    cout<<"Topo sort: ";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }   
}

void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 5;
    vector<int> adj[numnodes];

    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,4,3);

    cout<<"Adj list: "<<endl;   
    for(int i=0;i<numnodes;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    toposort(numnodes,adj);

    return 0;
}

