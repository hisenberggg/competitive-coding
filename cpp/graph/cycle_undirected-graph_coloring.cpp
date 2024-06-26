#include<bits/stdc++.h>
using namespace std;

UNRESOLVED

// Detect if there is a cycle present in a undirected graph
// using graph coloring method
// status:
// 0 = unvisited
// 1 = visited
// 2 = procressed 

// write functions here 
bool cycle_dfs(int node, vector<int> adj[], vector<int> status){
    if(status[node]==2)
        return true;

    for(auto it:adj[node]){
        if(status[it]==1) 
            status[it] = 2;
        else{
            status[node] = 1;
            if(cycle_dfs(it,adj,status))
                return true;
        }
    }
    return false;
}


void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 4;
    vector<int> adj[numnodes];
    // [[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,1);
    

    for(int i=0;i<numnodes;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    
    for(int i=0;i<numnodes;i++){
        vector<int> status(numnodes,0);
        status[i] = 1;
        cout<<"Cycle in the graph starting from "<<i<<": "<<(cycle_dfs(i,adj,status)?"true":"false")<<endl;
    }
    

    return 0;
}

