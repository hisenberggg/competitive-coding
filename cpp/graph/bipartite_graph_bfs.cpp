#include<bits/stdc++.h>
using namespace std;

bool isbipartite(int numnodes, vector<int> adj[]){
    queue<int> q;
    int colors[numnodes];
    for(int i=0;i<numnodes;i++) colors[i] = -1;

    q.push(0);
    colors[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(colors[it]==-1){
                colors[it] = !colors[node];
                q.push(it);
            }
            else if(colors[it]==colors[node]){
                return false;
            }
        }
    }
    return true;
}

void addedge(vector<int> adj[],int x,int y){
    adj[x].push_back(y);
}

int main(int argc, char const *argv[])
{
    int numnodes = 7;
    vector<int> adj[numnodes];

    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,6);
    addedge(adj,6,0);

    if(isbipartite(numnodes,adj)){
        cout<<"Bipartite";
    }
    else{
        cout<<"Not bipartite";
    }

    return 0;
}
