#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> inp = {4,1,2,1,2};
    set<int> s;

    for(int i:inp){
        if(s.count(i)){
            s.erase(i);
        }
        else{
            s.insert(i);
        }
    }
    cout<<"Single number: "<<*s.begin();
    return 0;
}
