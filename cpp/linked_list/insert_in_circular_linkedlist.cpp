#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertCurcular(ListNode* head, int value){
    if(head == NULL){
        ListNode* temp = new ListNode(value);
        temp->next = temp;
        return temp;
    }
    ListNode* temp = head->next;
    ListNode* prev = head;
    while(true){
        if(temp->val > value || temp == head){
            prev->next = new ListNode(value,temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> nodes = {1};
    ListNode* dummy = new ListNode();

    ListNode* temp = dummy;
    for(auto it:nodes){
        temp->next = new ListNode(it);
        temp = temp->next;
    }
    ListNode* head = dummy->next;

    // for regular linkedlist 
    // temp->next = NULL;

    // for circular list 
    temp->next = head;

    int insert_val = 0;
    head = insertCurcular(head,insert_val);

    cout<<head->val<<" ";
    temp = head->next;
    while(temp != head && temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    
    return 0;
}
