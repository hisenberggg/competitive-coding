#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,7,5};
    int s = 12;
    int n = arr.size();
    vector<int> output;

    int front = 0, back = 0;
    long long sum = 0;
    while(back<n){
        while(sum > s && front < back){
            sum -= arr[front];
            front++;
        }
        if(sum == s){
            output.push_back(front+1);
            output.push_back(back+1);
            break;
        }
        sum += arr[back];
        back++;
    }
    output.push_back(-1);
    for(auto i:output) cout<<i<<" ";

    return 0;
}