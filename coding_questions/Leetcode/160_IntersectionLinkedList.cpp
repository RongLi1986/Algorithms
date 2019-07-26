/*
intersection of Two Linked Lists My Submissions Question Solution 
Total Accepted: 43796 Total Submissions: 150009 Difficulty: Easy
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
*/

/*
solution: connect two list and try to create a "circle"
if circle is exists, these two lists have intersection. find cycle start node
if not return null;
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
        	return NULL;

        //connect list and create a "circle"
        //if circle is exists, these two lists have intersection.
        //if not return null;
        ListNode* ptr=headA
        while(ptr->next!=NULL)
        	ptr=ptr->next;

        //make a cicle
        ptr->next=headB;
        //detect this cycle
        ListNode* temp=detectCycle(headA);
        ptr->next=NULL;

        return temp;
    }

    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        //if(head->next==NULL) return NULL;
        
        ListNode* ptrFast=head;
        ListNode* ptrSlow=head;

        while(ptrFast!=NULL){
        	ptrFast=ptrFast->next;
        	ptrSlow=ptrSlow->next;

        	if(ptrFast!=NULL){
        		ptrFast=ptrFast->next;
        	}else{
        		return NULL;
        	}
        
        	if(ptrFast==ptrSlow){
        		ListNode* temp=head;
        		while(temp!=ptrSlow){
        			temp=temp->next;
        			ptrSlow=ptrSlow->next;
        		}

        		return temp;
        	}

        }

    }
};