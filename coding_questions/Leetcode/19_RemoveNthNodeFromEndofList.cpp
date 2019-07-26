//Remove Nth Node From End of List 
/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.*/


/*
use two pinter to node, firstly move pointer1 n steps
then move pointer1 and pointer2 together until pointer1 
reach end of the linkedlist
remove value of pointer2 (need another pointer to keep pre-node)

corner case:
1, list is empty.
2. list length < n
3. n's value (this question should confirm n is vaild)
4. remove first node
*/


#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.*/
 struct ListNode {
 	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        ListNode* temp;
        int i=1;   //1st node

        /*
        ListNode* ptr=head;
        while(ptr!=NULL){
			cout<<ptr->val<<endl;
            ptr=ptr->next;
        }
        */

        while(i<n){
            ptr1=ptr1->next;
            i++;
        }

        if(ptr1->next==NULL){  //ptr1 is end of list
                               //remove head node
        	head=head->next;
        	return head;
        }
        
        while(ptr1->next!=NULL){  //
            ptr1=ptr1->next;
            temp=ptr2;
            ptr2=ptr2->next;
        }
        
        //remove ptr2
        temp->next=ptr2->next;
        
        return head;
    }
};

int main(){
	//[1,2] 2  delete 1
	//[1] 1    delete 1
	ListNode* a=new ListNode(1);
	ListNode* b=new ListNode(2);
	a->next=b;

	Solution s;
	ListNode* ptr= s.removeNthFromEnd(a,1);
	while(ptr!=NULL){
			cout<<ptr->val<<endl;
            ptr=ptr->next;
        }

}
