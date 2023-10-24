#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    vector<int> arr={8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    for(int i=arr.size()-1;i>=0;i--){
        s.insert(arr[i]);
        auto it = s.find(arr[i]);
        auto next_it = ++it;
        if(next_it != s.end()) {arr[i] = *next_it;cout<<arr[i]<<"\n";}
        else arr[i] = -1;
    }
    for(auto p:arr) cout<<p<<" ";
    return 0;
}  
