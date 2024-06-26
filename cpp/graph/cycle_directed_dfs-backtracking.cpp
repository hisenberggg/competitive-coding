#include<bits/stdc++.h>
using namespace std;

// Detect if there is a cycle present in a directed graph
// using Backtracking 

// write functions here 
bool cycle_dfs(int node, vector<int> adj[], vector<bool> visited){
    
    // is node is already visited the cycle present 
    if(visited[node]) 
        return true;

    // if no adj, therefore no dependency, therefore no cycle 
    // int course schedule problem: no adj i.e. no prerequisite, therefore this course can be done 
    // therefore no cycle 
    if(!adj[node].size())
        return false;

    visited[node] = true;
    for(auto it:adj[node]){
        // if cycle is found then immediately return true 
        if(cycle_dfs(it,adj,visited))
            return true;
    }

    // if no cycle is detected after traversing neighbours
    // this means it is a good node 
    // therfore backtrack: set unvisited & and remove dependency by clearing adj of node
    visited[node] = false;
    adj[node].clear();
    // return false since no cycle 
    return false;
}


void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 20;
    vector<int> adj[numnodes];
    // [[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]
    addedge(adj,0,10);
    addedge(adj,3,18);
    addedge(adj,5,5);
    addedge(adj,6,11);
    addedge(adj,11,14);
    addedge(adj,13,1);
    addedge(adj,15,1);
    addedge(adj,17,4);

    for(int i=0;i<numnodes;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<numnodes;i++){
        vector<bool> visited(numnodes,false);
        cout<<"Cycle in the graph starting from "<<i<<": "<<(cycle_dfs(i,adj,visited)?"true":"false")<<endl;
    }
    

    return 0;
}

