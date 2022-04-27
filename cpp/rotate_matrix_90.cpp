#include<bits/stdc++.h>
using namespace std;

void swap_arr(vector<vector<int>>& a, int u, int v, int size){
    for(int i = 0; i < size ;i++ ){
        a[u][i] = a[u][i] + a[v][i];
        a[v][i] = a[u][i] - a[v][i];
        a[u][i] = a[u][i] - a[v][i];
    }
}

void swap_cell(vector<vector<int>>& a, int i, int j){
    a[i][j] = a[i][j] + a[j][i];
    a[j][i] = a[i][j] - a[j][i];
    a[i][j] = a[i][j] - a[j][i];
}

void rotate_90(vector<vector<int>>& arr, int u , int v){

    for(int i=0; i < u/2 ; i++){
        swap_arr(arr,i,u-i-1, v);
    }

    for(int i = 0; i < u; i++){
        for(int j = i+1; j<v ; j++){
            swap_cell(arr,i,j);
        }
    }

    for(auto p:arr){
        for(auto q:p){
            cout<<q;
        }
        cout<<"\n";
    }


}

int main()
{
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    int u = arr.size(), v = arr[0].size();

    for(auto p:arr){
        for(auto q:p){
            cout<<q;
        }
        cout<<"\n";
    }
    cout<<"\n";

    rotate_90(arr,u,v);
    return 0;
}


// 123
// 456
// 789

// 741
// 852
// 963