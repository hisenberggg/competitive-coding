#include<bits/stdc++.h>
using namespace std;

// keys stored in sorted order
// map in C++ is based on red-black trees - self balanced binary trees.

int main(){

    map<string,int> mp;
    mp["India"] = 1;
    mp["America"] = 2;
    mp["England"] = 3;

    // ============> Accessing
    cout<< mp["India"]<<endl;     
    cout<< mp.at("India")<<endl;  //using .at()

    mp.at("India") = 4; // If index not present throws an error...whereas [] adds a new key
    cout<<mp.max_size()<<endl;


    return 0;
}

