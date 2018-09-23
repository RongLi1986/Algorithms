//Linked List Cycle 
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
fast and slow ptr:
fast move two step and slow one move one step
if they meet, it return true;
if fastptr==NULL, return false;
*/

#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	ListNode* ptrFast=head;
    	ListNode* ptrSlow=head;

    	while(ptrFast!=NULL){
    		ptrSlow=ptrSlow->next;
    		ptrFast=ptrFast->next;
    		
    		if(ptrFast!=NULL)
    			ptrFast=ptrFast->next;
    		else
    			return false;

    		if(ptrFast==ptrSlow)
    			return true;

    	}

    	return false;
        
    }
};


int main(){

    return 1;
}