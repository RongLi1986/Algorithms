/*
Copy List with Random Pointer

 Description
 Notes
 Testcase
 Judge
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/*

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* ptr=head;
        
        //insert copy nodes
        while(ptr!=NULL){
            RandomListNode* tmp=new RandomListNode(ptr->label);
            RandomListNode* next=ptr->next;
            ptr->next=tmp;
            tmp->next=next;
            
            ptr=next;
        }
        
        //build random ptr
        ptr=head;
        while(ptr!=NULL){
            if(ptr->random!=NULL)
                ptr->next->random=ptr->random->next;
            
            ptr=ptr->next->next;
        }
        
        //divide this list to two
        ptr=head;
        RandomListNode* outhead=NULL;
        while(ptr!=NULL){
            RandomListNode* tmp=ptr->next;
            if(outhead==NULL) outhead=tmp;
            ptr->next=tmp->next;
            
            if(ptr->next!=NULL)
                tmp->next=ptr->next->next;
            
            ptr=ptr->next;
        }
        
        
        return outhead;
    }
};