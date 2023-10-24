#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    int N = A.size();
    int edgeX, edgeY;
    int y=0;
    while(y<N){
        edgeX=0;edgeY=y;
        while(edgeY>=0){
            cout<<A[edgeX][edgeY]<<" ";
            edgeX++;edgeY--;
            cout<<"";
        }
        y++;
    }

    int x = 1;
    while(x<N){
        edgeY=N-1;edgeX=x;
        while(edgeX<N){
            cout<<A[edgeX][edgeY]<<" ";
            edgeX++;edgeY--;
        }
        x++;
    }
    return 0;
}