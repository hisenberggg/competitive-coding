#include<bits/stdc++.h>
using namespace std;

// write functions here 
void bfs(int node, vector<int> adj[], bool visited[]){
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
}


void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 5;
    vector<int> adj[numnodes];

    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,4);
    addedge(adj,1,4);
    addedge(adj,4,2);
    addedge(adj,3,2);

    for(int i=0;i<numnodes;i++){
        cout<<i<<": ";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    bool visited[numnodes] = {false};
    cout<<"BFS: ";
    bfs(1,adj, visited);        

    return 0;
}

