#include<bits/stdc++.h>
using namespace std;

// Time complexity: Elog(V) 

vector<int> dijkstras(vector<vector<int>> adj[], int numnodes, int source_node){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,source_node));
    vector<int> mindist(numnodes,INT_MAX);

    mindist[source_node] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        
        for(auto it:adj[node]){
            if(mindist[node]+it[1]<mindist[it[0]]){
                mindist[it[0]] = mindist[node] + it[1];
                pq.push(make_pair(mindist[it[0]],it[0]));
            }
        }
    }
    return mindist;
}

void addedge(vector<vector<int>> adj[], int x, int y, int wt){
    adj[x].push_back({y,wt});
}

int main(int argc, char const *argv[])
{
    int numnodes = 6;
    vector<vector<int>> adj[numnodes];
    addedge(adj,0,1,4);
    addedge(adj,0,2,4);
    addedge(adj,1,0,4);
    addedge(adj,1,2,2);
    addedge(adj,2,0,4);
    addedge(adj,2,1,2);
    addedge(adj,2,3,3);
    addedge(adj,2,4,1);
    addedge(adj,2,5,6);
    addedge(adj,3,2,3);
    addedge(adj,3,5,2);
    addedge(adj,4,2,1);
    addedge(adj,4,5,3);
    addedge(adj,5,4,3);
    addedge(adj,5,2,6);
    addedge(adj,5,3,2);
    vector<int> mindist = dijkstras(adj,numnodes,0);

    for(int i=0;i<numnodes;i++){
        cout<<i<<": "<<mindist[i]<<endl;
    }
    return 0;
}
