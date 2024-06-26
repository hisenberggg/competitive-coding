#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2){
    if(m1.end<m2.end){
        return true;
    }
    else if(m1.end>m2.end){
        return false;
    }
    else if(m1.pos<m2.pos){
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int n = start.size();

    struct meeting ds[n];

    // push data to datastructure 
    for(int i=0;i<n;i++){
        ds[i].start = start[i];
        ds[i].end = end[i];
        ds[i].pos = i+1;
    }

    // sort the datastructure as per the end 
    sort(ds,ds+n,comparator);
    
    // get the meetings that can be conducted one after the other
    vector<int> answer;
    answer.push_back(ds[0].pos);
    int limit = ds[0].end;

    for(int i=1;i<n;i++){
        if(ds[i].start > limit){
            limit = ds[i].end;
            answer.push_back(ds[i].pos);
        }
    }

    cout<<"Total nummber of meeting: "<<answer.size()<<endl;
    for(auto it:answer)
        cout<<it<<" ";
    return 0;
}
