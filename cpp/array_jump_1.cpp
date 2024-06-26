// given an array find whether we can reach the end of the array or not
// constraints: 0 <= a[i] <= positive integer
// a[i] is the max jump you can make

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1,1,2,3,2,1,0,0,1,3};
    int reachable = 0, n = a.size();
    string status;
    for(int i=0;i<n;i++){
        
        // if the current element is 0 and the reachablity is less then current position 
        // then it is not possible to reach the end
        if(a[i] == 0 && i > reachable){
            status = "cant reach";
            break;
        }
        // if the reacablity from current item is greater then previous reach value, 
        // then update the reachablity
        if(a[i] + i > reachable){
            reachable = a[i] + i;
            if(reachable>n-1){
                reachable = n;
            }
        }
        if(reachable == n-1){
            status = "reached";
            break;
        }
        // cout<<i<<" "<<reachable<<endl;
    }


    cout<<"Status: "<<status;

    return 0;
}
