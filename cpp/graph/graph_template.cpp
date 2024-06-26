#include<bits/stdc++.h>
using namespace std;

// write functions here 



void addedge(vector<int> adj[],int source, int dest){
    adj[source].push_back(dest);
}
int main() {
	// your code goes here
    int numnodes = 10;
    vector<int> adj[numnodes];

    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,5);
    addedge(adj,1,5);
    addedge(adj,5,2);
    addedge(adj,3,2);

    return 0;
}

