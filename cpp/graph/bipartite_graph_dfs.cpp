#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], int color[], int c){
    if(color[node]!=-1){
        if(color[node]==c) return true;
        else return false;
    }

    color[node] = c;
    
    for(auto it:adj[node]){
        if(dfs(it,adj,color,!c)) return true;
        else return false;
    }
}

bool isbipartite(int numnodes, vector<int> adj[]){
    int color[numnodes];
    for(int i=0;i<numnodes;i++) color[i] = -1;

    for(int i=0;i<numnodes;i++){
        if(color[i]==-1){
            if(!dfs(i,adj,color,0)) 
                return false;
        }
    }
    return true;
}

void addedge(vector<int> adj[], int x, int y){
    adj[x].push_back(y);
}
int main(int argc, char const *argv[])
{
    int numnodes = 10;
    vector<int> adj[numnodes];
    
    // graph 1 - not
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,6);
    addedge(adj,6,1);

    // graph 2 - yes
    addedge(adj,7,8);
    addedge(adj,8,9);
    addedge(adj,9,7);


    if(isbipartite(numnodes,adj)){
        cout<<"Bipartite";
    }
    else{
        cout<<"Not a bipartite";
    }
    return 0;
}
