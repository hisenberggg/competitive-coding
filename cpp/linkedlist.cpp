#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

struct Node* add(struct Node* head1, struct Node* head2){
    while(head1 != NULL && head2 != NULL){
        
    }



    return head1;
}
 
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* op;

 
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);

    push(&head2, 5);
    push(&head2, 6);
  

    op = add(head1,head2);
 
    return 0;
}