//Merge Two Sorted Lists 
/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
#include <iostream>
using namespace std;

/*
I think this is final part of merge sort 
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
    ListNode *mergeTwoLists_old(ListNode *l1, ListNode *l2) {
    	if(l1==NULL&&l2==NULL)
    		return NULL;
    	if(l1==NULL)
    		return l2;
    	if(l2==NULL)
    		return l1;

    	ListNode* OutHeadptr=(l1->val < l2->val)? l1:l2;
    	ListNode* ptr1=l1;
    	ListNode* ptr2=l2;
    	//cout<<ptr2->val<<endl;
    	
    	if(OutHeadptr==l1){
    		ptr1=ptr1->next;
    	}
    	else{
    		ptr2=ptr2->next;
    	}
    	
    	OutHeadptr->next=NULL;
    	
    	ListNode* temp=OutHeadptr;

    	while(ptr1!=NULL && ptr2!=NULL){
    		if(ptr1->val < ptr2->val){
    			temp->next=ptr1;
    			ptr1=ptr1->next;
    			temp=temp->next;
    			temp->next=NULL;
    		}else{
    			temp->next=ptr2;
    			ptr2=ptr2->next;
    			temp=temp->next;
    			temp->next=NULL;
    		}
    	}

    	if(ptr1!=NULL){
    		temp->next=ptr1;
    	}

    	if(ptr2!=NULL){
    		temp->next=ptr2;
    	}


    	return OutHeadptr;
    }


    //this sol is faster
    ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
    }
}


};


int main(){
	ListNode* l1=new ListNode(1);
	ListNode* l2=new ListNode(2);
	
	Solution s;
	ListNode* ptr=s.mergeTwoLists(l1,l2);

	while(ptr!=NULL){
		cout<<ptr->val<<"-";
		ptr=ptr->next;
	}
	cout<<endl;

	return 0;
}