/*
Merge Two Sorted Lists

 Description
 Notes
 Testcase
 Judge
Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.

Have you met this question in a real interview? Yes
Example
Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.
*/

/*

*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val <= ptr2->val){
                if(head==NULL){
                    head=ptr1;
                    tail=ptr1;
                }else{
                    tail->next=ptr1;
                    tail=ptr1;
                }
                ptr1 = ptr1->next;
            }else{
                if(head==NULL){
                    head=ptr2;
                    tail=ptr2;
                }else{
                    tail->next=ptr2;
                    tail=ptr2;
                }
                ptr2 = ptr2->next;
            }
            tail->next =NULL;
        }
        
        if(ptr1!=NULL){
            if(head == NULL){
                head = ptr1;
                tail = ptr1;
            }else{
                tail->next = ptr1;
            }
        }
        
        if(ptr2!=NULL){
            if(head == NULL){
                head = ptr2;
                tail = ptr2;
            }else{
                tail->next = ptr2;
            }
        }
        
        return head;
    }
};