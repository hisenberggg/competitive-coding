#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int limit = 2*n-1,row_limit;
        for(int i=n; i>0; i--){
            row_limit = 2*i-1;
            if(row_limit < limit){
                for(int j=n; j>i; j--){
                    cout<<j<<" ";
                }
            }
            for(int k=2*i-1;k>0;k--){
                cout<<i<<" ";
            }
            if(row_limit < limit){
                for(int j=i+1; j<=n; j++){
                    cout<<j<<" ";
                }
            }
            cout<<"\n";
        }
        for(int i=2; i<=n; i++){
            row_limit = 2*i-1;
            if(row_limit < limit){
                for(int j=n; j>i; j--){
                    cout<<j<<" ";
                }
            }
            for(int k=2*i-1;k>0;k--){
                cout<<i<<" ";
            }
            if(row_limit < limit){
                for(int j=i+1; j<=n; j++){
                    cout<<j<<" ";
                }
            }
            cout<<"\n";
        }
    return 0;
}