#include<bits/stdc++.h>
using namespace std;

void get_path(int dest, vector<int> &path, vector<int> &parent, int source){
    if(dest==source){
        path.push_back(source);
        return;
    }
    get_path(parent[dest],path,parent,source);
    path.push_back(dest);
}

vector<int> dijkstras(vector<vector<int>> adj[], int numnodes, int source, int dest){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> mindist(numnodes,INT_MAX);
    vector<int> parent(numnodes,-1);

    pq.push(make_pair(0,source));
    mindist[source] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int neb = it[0];
            int nebdist = it[1];
            if(mindist[node]+nebdist<mindist[neb]){
                mindist[neb] = mindist[node]+nebdist;
                pq.push(make_pair(mindist[neb],neb));
                parent[neb] = node;
            }
        }
    }
    cout<<"Mindist from "<<source<<" to "<<dest<<" is: "<<mindist[dest]<<endl;
    vector<int> path;
    get_path(dest,path,parent,source);
    return path;
}

void addedge(vector<vector<int>> adj[], int x, int y, int wt){
    adj[x].push_back({y,wt});
}

int main(int argc, char const *argv[])
{
    int numnodes = 6; //num nodes 5 starting from index 1->5
    vector<vector<int>> adj[numnodes];
    addedge(adj,1,2,2);
    addedge(adj,1,4,1);
    addedge(adj,2,1,2);
    addedge(adj,2,3,4);
    addedge(adj,2,5,5);
    addedge(adj,5,2,5);
    addedge(adj,5,3,1);
    addedge(adj,3,2,4);
    addedge(adj,3,5,1);
    addedge(adj,3,4,3);
    addedge(adj,4,1,1);
    addedge(adj,4,3,3);

    int source = 1;
    int dest = 5;

    vector<int> path = dijkstras(adj,numnodes,source,dest);
    cout<<"Path: ";
    for(auto it:path){
        cout<<it<<" ";
    }
    return 0;
}
