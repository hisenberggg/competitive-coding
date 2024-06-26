#include<bits/stdc++.h>
using namespace std;

double get_median(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();

    if(n>m){
        return get_median(b,a);
    }
    

    int low = 0;
    int high = n;
    int left = (n+m+1)/2;
    

    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(mid1-1>=0) l1 = a[mid1-1];
        if(mid2-1>=0) l2 = b[mid2-1];
        if(mid1<=n-1) r1 = a[mid1];
        if(mid2<=m-1) r2 = b[mid2];

        if(l1<=r2 && l2<=r1){
            if((m+n)%2==0){
                return (double) (max(l1,l2)+min(r1,r2))/2.0;
            }
            else{
                return (double) max(l1,l2);
            }
        }
        else if(l1>r2){
            high = mid1-1;
        }
        else if(l2>r1){
            low = mid1+1;
        }
    }
    return 0;
}

int main(){
    vector<int> a = {1,2,3,5,6};
    vector<int> b = {4};

    double median = get_median(a,b);
    cout<<"Median is: "<<median;
    return 0;
}