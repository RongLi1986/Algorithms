/*
Linked List Cycle II

Given a linked list, return the node where the cycle begins.

If there is no cycle, return null.

Have you met this question in a real interview? Yes
Example
Given -21->10->4->5, tail connects to node index 1，return 10
*/

/*
??
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(head==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* ptr=head;;
        
        while(1){
            fast=fast->next;
            if(fast==NULL)
                return NULL;
            fast=fast->next;
            if(fast==NULL)
                return NULL;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        
        while(1){
            slow=slow->next;
            ptr=ptr->next;
            if(ptr==slow)
                return ptr;
        }
    }
};


