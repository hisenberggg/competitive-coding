#include<bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    head = addNode(head,4);
    head = addNode(head,3);
    head = addNode(head,3);
    head = addNode(head,4);
    cout<<"List: ";
    printList(head);
    // =============================================== //

    // start code here 
    Node *slow = head, *fast = head;
    vector<int> st;

    while(fast != NULL && fast->next != NULL){
        st.push_back(slow->data);
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast != NULL){
        slow = slow->next;
    }

    int n = st.size()-1;
    bool flag = true;

    while(slow != NULL){
        if(slow->data != st[n]){
            flag = false;
            break;
        }
        n--;
        slow = slow->next;
    }
    
    if(flag){
        cout<<"List is a palindrom.";
    }
    else{
        cout<<"List is not a palindrom.";
    }

    return 0;
}
