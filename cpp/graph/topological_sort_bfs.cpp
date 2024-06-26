#include<bits/stdc++.h>
using namespace std;

// Topological sort the graph
// pre-requisite = Directed, Acyclic graph (DAG)

// write functions here 

void toposort(int numnodes, vector<int> adj[]){
    int indegree[numnodes] = {0};
    for(int i=0;i<numnodes;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<numnodes;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        
        for(auto it:adj[node]){
            indegree[it]--;

            if(indegree[it]==0)
                q.push(it);
        }
    }

    cout<<"Topological sort BFS: ";
    for(auto it:ans){
        cout<<it<<" ";
    }
}

void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 6;
    vector<int> adj[numnodes];

    addedge(adj,0,1);
    addedge(adj,2,1);
    addedge(adj,1,3);
    addedge(adj,3,2);
    addedge(adj,4,3);

    // addedge(adj,5,2);
    // addedge(adj,5,0);
    // addedge(adj,4,0);
    // addedge(adj,4,1);
    // addedge(adj,2,3);
    // addedge(adj,3,1);

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

