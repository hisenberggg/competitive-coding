/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int d = 1,f = 0;
        ListNode *temp = head, *fwd = head,*prev = NULL;
        
        #if there is only one node
        if(!fwd->next){
            delete(head);
            head = NULL;
            return head;
        }

        while(fwd->next){
            if(d % n == 0 or f==1){
                f = 1;
                prev = temp;
                temp = temp->next;
            }
            fwd = fwd->next;
            d++;
        }
        
        #if deleting the 1st element(nth from behind) then shift the head ahead
        if(d == n){
            head = head->next;
            delete(temp);
            return head;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
        
    }
};