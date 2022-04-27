#include<bits/stdc++.h>
using namespace std;

int sort(int temp[], int a[], int l, int mid, int u){
    int i = l,j = mid+1, k = l, inv_count = 0;

    while(i<=mid && j<=u){
        if(a[i]<=a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
            inv_count += (mid - i + 1);
        }
        k++;
    }
    while(i<=mid){
        temp[k] = a[i];
        k++;i++; 
    }
    while(j<=u){
        temp[k] = a[j];
        k++;j++;
    }
    for(int p = l; p<=u ; p++){
        a[p] = temp[p];
    }
    return inv_count;

}

int mergesort(int temp[], int a[], int l,int u){
    int mid, inv_count = 0;
    if(l<u){
        mid = (u+l)/2;
        inv_count += mergesort(temp,a,l,mid);
        inv_count += mergesort(temp,a,mid+1,u);

        inv_count += sort(temp,a,l,mid,u);
    }

    return inv_count;
}

int main(){

    int a[] = {5,4,3,2,1};
    int n = 5;
    int temp[n];

    cout<<"Count of inversion pairs: "<<mergesort(temp,a,0,n-1);

    return 0;
}