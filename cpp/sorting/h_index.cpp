#include<bits/stdc++.h>
using namespace std;

int getHIndex(vector<int> citations){

    sort(citations.begin(),citations.end());

    int n = citations.size();
    int low = 0, high = n;

    while(low<=high){ // apply binary search on sorted arr
        int mid = (high+low)/2; // calculate mid

        if(citations[mid]==(n-mid)){  // if we found exact no. of citations, then that's optimal
            return citations[mid]; // or return (n-mid)
        }
        else if(citations[mid]<(n-mid)){
            low = mid + 1;              // final value will be stored in the low
        }
        else{
            high = mid - 1;
        }
    }
    return n-low;
}

int main(int argc, char const *argv[])
{
    vector<int> citations = {3,0,6,1,5};
    // vector<int> citations = {0,1,3,5,6};
    // vector<int> citations = {1,1,3};

    int index = getHIndex(citations);

    cout<<"H-index is: "<<index;
    return 0;
}
