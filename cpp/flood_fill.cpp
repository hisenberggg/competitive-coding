#include<iostream>
#include <bits/stdc++.h>
// #include<vector>
using namespace std;

void fill(vector<vector<int>>& image, int sr, int sc, int color, int newColor,vector<vector<int>>& visited){
    // cout<<"test"<<sr<<" "<<sc<<"\n";
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;
            if(sr-1>=0){
                if(!visited[sr-1][sc]){
                    visited[sr-1][sc] = 1;
                    fill(image,sr-1,sc,color,newColor,visited);
                }   
            }
            if(sr+1<image.size()){
                if(!visited[sr+1][sc]){
                    visited[sr+1][sc] = 1; 
                    fill(image,sr+1,sc,color,newColor,visited);
                }
            }
            if(sc-1>=0){
                if(!visited[sr][sc-1]){
                    visited[sr][sc-1] = 1;
                    fill(image,sr,sc-1,color,newColor,visited);
                }
            }
            if(sc+1<image[0].size()){
                if(!visited[sr][sc+1]){
                    visited[sr][sc+1] = 1;
                    fill(image,sr,sc+1,color,newColor,visited);
                }
            }
        } 
        return;
    }

int main(){
    int sr = 1, sc = 1, newColor = 2, inp;
    vector<vector<int>> image;
    
    cout<<"INPUT: \n";
    for(int i=0;i<3;i++){
        vector<int> temp;
        for(int j=0;j<3;j++){
            cin>>inp;
            temp.push_back(inp);
        }
        image.push_back(temp);
    }
    cout<<"before:\n";
    for(vector<int> i:image){
        for(int j:i)
            cout<<j;
        cout<<"\n";
    }

    vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));

    fill(image,sr,sc,image[sr][sc],newColor,visited);

    cout<<"output:\n";
    for(vector<int> i:image){
        for(int j:i)
            cout<<j;
        cout<<"\n";
    }
        
    return 0;
}