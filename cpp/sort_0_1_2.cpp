#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>& a, int i, int k){
    a[i] = a[i] + a[k];
    a[k] = a[i] - a[k];
    a[i] = a[i] - a[k];
}

void sort012(vector<int>& a, int n){
    int l = 0, m = 0, h = n-1;
    while(m < h){
        if(a[m] == 0){
            swap(a,m,l);
            l++;m++;
        }
        else if(a[m] == 1){
            m++;
        }
        else{
            swap(a,m,h);
            h--;
        }
    }
}


int main(){
    
    vector<int> a = {2,0,0,1,2,0,1,2,0,1};
    int n = a.size();

    sort012(a,n);

    cout<<"Sorted array: ";
    for(auto p:a){
        cout<<p<<" ";
    }

    return 0;
}
