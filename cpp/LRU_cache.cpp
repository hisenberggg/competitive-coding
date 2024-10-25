#include<bits/stdc++.h>
using namespace std;

class LRU_cache {
    class node{
        public:
            int val;
            int key;
            node* next;
            node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int capacity;
    unordered_map<int,node*> mpp;

    LRU_cache(int _capacity){
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newnode){
        node* temp = head->next;

        head->next = newnode;
        newnode->prev = head;

        newnode->next = temp;
        temp->prev = newnode;
    }

    int get(int key){
        if(mpp.find(key) != mpp.end()){
            node* temp = mpp[key]->val;
            return ;
        }
    }

    void put(int key, int val){

    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
