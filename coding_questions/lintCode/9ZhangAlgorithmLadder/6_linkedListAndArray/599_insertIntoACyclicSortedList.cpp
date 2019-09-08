/*
Insert into a Cyclic Sorted List

Given a node from a cyclic linked list which has been sorted, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be any single node in the list. Return the inserted new node.

 Notice

3->5->1 is a cyclic list, so 3 is next node of 1.
3->5->1 is same with 5->1->3

Example
Given a list, and insert a value 4:
3->5->1
Return 5->1->3->4
*/

/*
cut list
insert node 
connected
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
     * @param node a list node in the list
     * @param x an integer
     * @return the inserted new list node
     */
    ListNode* insert(ListNode* node, int x) {
        // Write your code here
        if(node==NULL) {
            ListNode* newNode = new ListNode(x);
            newNode->next = newNode;
            return newNode;
        }
        
        ListNode* ptr = node;
        ListNode* min =node;
        ListNode* max = node;
        
        //detect min and max
        while(1){
            ptr=ptr->next;
            
            if(ptr==node)
                break;
            
            if(max->val<=ptr->val){
                max = ptr;
            }
        }
        min = max->next;
        
        //cut cycle list
        if(min==max){ //same value
            min = max->next;
            ListNode* newNode = new ListNode(x);
            newNode->next =min;
            min=newNode;
            max->next = min;
            return newNode;
        }else{
            max->next == NULL;
        }
        
        
        //insert node and connect list back to cycle
        ptr = min;
        
        while(ptr!=max){
            if(ptr->val<=x && ptr->next->val>=x){
                ListNode* newNode = new ListNode(x);
                ListNode* tmp = ptr->next;
                ptr->next = newNode;
                newNode->next = tmp;
                max->next = min;
                return newNode;
            }else{
                ptr=ptr->next;
            }
        }
        
        //x > than max ot < min
        ListNode* newNode = new ListNode(x);
        ptr->next = newNode;
        max = newNode;
        max->next = min;
        return newNode;
    }
};
