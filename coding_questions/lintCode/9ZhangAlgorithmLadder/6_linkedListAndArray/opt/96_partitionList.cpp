/*
Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.
*/

/*
merge
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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head==NULL) return NULL;
        ListNode* ptr = head;
        
        ListNode* smallHead = NULL;
        ListNode* smallTail = NULL;
        ListNode* largeHead = NULL;
        ListNode* largeTail = NULL;
        
        while(ptr!=NULL){
            ListNode* tmp=ptr;
            ptr=ptr->next;
            tmp->next=NULL;
            if(tmp->val<x){ //put into small list
                if(smallHead == NULL){
                    smallHead = tmp;
                }else{
                    smallTail->next = tmp;
                }
                smallTail = tmp;
            }else{ //put into large list
                if(largeHead == NULL){
                    largeHead = tmp;
                }else{
                    largeTail->next = tmp;
                }
                largeTail = tmp;
            }
        }
        
        //connect small and large list
        if(smallHead!=NULL){
            smallTail->next=largeHead;
            return smallHead;
        }else{
            return largeHead;
        }
    }
};