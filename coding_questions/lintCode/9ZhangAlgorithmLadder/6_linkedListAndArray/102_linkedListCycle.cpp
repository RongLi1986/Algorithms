/*
Linked List Cycle
Given a linked list, determine if it has a cycle in it.



Have you met this question in a real interview? Yes
Example
Given -21->10->4->5, tail connects to node index 1, return true
*/

/*
fast and slow pointers
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        ListNode* fast =  head;
        ListNode* slow =  head;
        
        while(fast!=NULL){
            fast=fast->next;
            if(fast==NULL)
                break;
            fast=fast->next;
            slow=slow->next;
            
            if(fast==slow)
                return true;
        }
        
        return false;
    }
};


