#include<iostream>
#include<bits/stdc++.h>
// #include<vector>
using namespace std;

int main(){
    int t,x,y,r,c;
    char inp;
    
    cin>>t;
    while(t--){
        vector<vector<char>> arr;
        cin>>r>>c>>x>>y;
        for(int i=0;i<r;i++){
            vector<char> temp;
            for(int j=0;j<c;j++){
                cin>>inp;
                temp.push_back(inp);
            }
            arr.push_back(temp);
            temp.clear();
        }
        x--;y--;

        if(arr[x][y] == 'B')
            cout<<0<<"\n";
        else{
            int f=0;
            for(int i=0;i<c;i++){
                if(arr[x][i]=='B'){
                    cout<<1<<"\n";
                    f=1;
                    break;
                }
            }
            if(f)
                continue;
            for(int i=0;i<r;i++){
                if(arr[i][y]=='B'){
                    cout<<1<<"\n";
                    f=1;
                    break;
                }
            }
            if(f)
                continue;
            f = 0;
            for(int i =0;i<r;i++){
                if(count(arr[i].begin(),arr[i].end(),'B')){
                    cout<<2<<"\n";
                    f=1;
                    break;
                }
            }
            if(!f)
                cout<<-1<<"\n";
        }   
        
    }
    return 0;
}
