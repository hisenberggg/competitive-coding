#include<bits/stdc++.h>
#include "LinkedList.h"

using namespace std;


Node *reverse_ll(Node *start, int i,int n, int b[]){ 
	if(start == NULL){
		return NULL;
	}

    // skip while the b[i] is 0  
    while(b[i]==0){
		i+=1;
        if(i>=n) break;
	}

    // if b is exhausted then return start (keep as it is)
	if(i>=n){
		return start;
	}

	Node *prev = NULL, *curr = start, *front = start;

	int count = 0;
	while(count<b[i] && front != NULL){
		front = front->next;
		curr->next = prev;
        prev = curr;
		curr = front;
		count++;
	}

	start->next = reverse_ll(curr,i+1,n,b);
	return prev;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    head = addNode(head,1);
    head = addNode(head,2);
    head = addNode(head,3);
    head = addNode(head,4);
    head = addNode(head,5);
    head = addNode(head,6);
    head = addNode(head,7);
    head = addNode(head,8);
    head = addNode(head,9);
    head = addNode(head,10);
    head = addNode(head,11);
    cout<<"List: ";
    printList(head);
    // =============================================== //

    // start code here 

    int b[] = {3,3,2};
    int n = sizeof(b)/sizeof(b[0]);

    head = reverse_ll(head,0,n,b);

    cout<<"Reversed list as per b[k]:";
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}

}
