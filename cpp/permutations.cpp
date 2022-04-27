// https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=32s
// time complexity : N! since the recursion is going to generate all the permutations
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& a, int i, int p){
    int t;
    t = a[i];
    a[i] = a[p];
    a[p] = t;
}

void get_permutations(vector<int>& a, int i,int n){
    if(i == n){
        for(auto p:a)
            cout<<p<<" ";
        cout<<endl;
        return;
    }
    for(int p = i; p < n ; p++){
        swap(a,i,p);
        get_permutations(a,i+1,n);
        swap(a,i,p);
    }
}

int main()
{   
    int n = 3;
    vector<int> a = {1,2,3};
    get_permutations(a,0,n);
    return 0;
}









/*
// this code uses t vector and n!*n space

vector<int> swap(vector<int> a,int i,int k){
    int temp;
    temp = a[i];
    a[i] = a[k];
    a[k] = temp;
    return a;
}

void getpermutations(vector<vector<int>>& op,vector <int> a, int i, int n){
    if(i==n){
        op.push_back(a);      
        // return;
    }
    vector<int> t;
    for(int k = i;k < n; k++){
        t = swap(a,i,k);
        getpermutations(op,t,i+1,n);
    }
}

int main(int argc, char const *argv[])
{
    vector <int> a = {1,2,3,4,5};
    vector<vector<int>> op;
    int n = a.size();
    getpermutations(op,a,0,n);
    cout<<"All permutations:\n";
    for(vector<int> o:op){
        for(int p:o)
            cout<<p<<" ";
        cout<<"\n";
    }
    return 0;
}
*/