#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main()
{
    vector<int> nodes = {1,2,3,4};
    ListNode* dummy = new ListNode();

    ListNode* temp = dummy;
    for(auto it:nodes){
        temp->next = new ListNode(it);
        temp = temp->next;
    }
    ListNode* head = dummy->next;

    // for regular linkedlist 
    temp->next = NULL;

    // for circular list 
    // temp->next = head;

    // ============xxx============= //

    
    return 0;
}
