#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int i){
    if(!heap.size()) return;

    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;

    if(left<=heap.size()-1 && heap[left]<heap[smallest]){
        smallest = left;
    }
    if(right<=heap.size()-1 && heap[right]<heap[smallest]){
        smallest = right;
    } 

    if(i!=smallest){
        swap(heap[i],heap[smallest]);
        heapify(heap, smallest);
    }
}

void percolateUp(vector<int> &heap, int i){
    int parent = ceil(heap.size()/2)-1;
    while(heap[parent]>heap[i] && i>0){
        swap(heap[parent],heap[i]);
        i = parent;
        parent = ceil((i+1)/2)-1;
    }
}

int main(){
    vector<int> heap;
    vector<vector<int>> q = {
                            {0,30},
                            {0,18},
                            {0,40},
                            {0,25},
                            {1},
                            {0,14},
                            {0,13},
                            {1},
                            {0,9},
                            {0,11},
                            {1}
                            };

    for(auto it:q){
        if(it[0]==0){
            heap.push_back(it[1]);
            percolateUp(heap, heap.size()-1);
        }
        else{
            if(!heap.size()) continue;
            cout<<"min: "<<heap[0]<<endl;
            heap[0] = heap[heap.size()-1];
            heap.pop_back();
            heapify(heap, 0);
        }
    }
}
