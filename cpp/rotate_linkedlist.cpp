#include<bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int getCount(Node *head, int k){
    int count = 1;
    Node *temp = head;
    while(temp->next != NULL){
        count++;
        head = temp->next;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    /* code */
    Node *head = NULL;
    head = addNode(head,1);
    head = addNode(head,2);
    head = addNode(head,3);
    head = addNode(head,4);
    head = addNode(head,5);
    printList(head);

    int k = 2;
    // write code from here
    int count =  getCount(head,k);
    k = k%count;
    cout<<"k = "<<k<<endl;
    
    Node *temp = head;
    for(int i=0;i<count-k;i++){
        temp = temp->next;
    }
    Node *begin = temp;
    begin = begin->next;
    temp->next = addNode(temp->next,0);
    temp->next = NULL;

    Node *start = begin;
    while(begin->next != NULL){
        begin = begin->next;
    }
    begin->next = head;
    head = start;

    cout<<"output: ";
    printList(head);
    return 0;
}
