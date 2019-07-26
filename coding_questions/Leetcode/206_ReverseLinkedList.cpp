/*
Reverse Linked List
Reverse a singly linked list.
*/

/*
drop input list head and insert  it to target list from front
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr=head;
        ListNode* head_out=NULL;
       
        while(ptr!=NULL){
            ListNode* tmp=ptr;
            ptr=ptr->next;
            tmp->next=head_out;
            head_out=tmp;
        }
        
        return head_out;
    }
};

class Solution_old {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* ptr=head;
        ListNode* previous=NULL;
        
        while(ptr!=NULL){
            if(previous==NULL){
                ListNode* tmp=ptr;
                ptr=ptr->next;
                tmp->next=NULL;
                previous=tmp;
            }else{    
                ListNode* tmp=ptr;
                ptr=ptr->next;
                tmp->next=previous;
                previous=tmp;
            }
        }
        
        return previous;
        
    }
};