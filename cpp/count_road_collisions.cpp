#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string directions = "RLRSLL";
    int rc = 0, ims = 0, coll = 0; //ims-> immediate still car exist flag 0/1
    char prev = 'L';

    for(int i=0; i<directions.size(); i++){
        if(directions[i] == 'R'){
            rc += 1;
            ims = 0;
        }
        else if(directions[i] == 'L'){
            if(prev == 'R'){
                coll += 2;
                ims = 1;
            }
            else if(ims == 1){
                coll += 1;
            }
            rc = 0;
        }
        else if(directions[i] == 'S'){
            ims = 1;
            if(rc > 0){
                coll += rc;
            }
            rc = 0;
        }
        prev = directions[i];
    }
    cout<<"Collisions are: "<<coll;

    return 0;
}
