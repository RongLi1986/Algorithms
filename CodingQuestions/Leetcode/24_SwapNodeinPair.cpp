/*
Swap Nodes in Pairs 
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
*/

/*
it can directly swap in linkedlist
*/


/**
 * Definition for singly-linked list.
 */
#include <iostream>
 using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
 		if(head==NULL || head->next==NULL) return head;
 		ListNode* ptr=head;
 		head=NULL;
 		ListNode* tail=NULL;
 		ListNode* tmp1=NULL;
 		ListNode* tmp2=NULL;
 		while(ptr!=NULL){
 			tmp1=ptr;
 			ptr=ptr->next;
 			tmp1->next=NULL;
 			if(ptr!=NULL){
 				tmp2=ptr;
 				ptr=ptr->next;
 				tmp2->next=NULL;
 			}else{
 				//put last one
 				tail->next=tmp1;
 				break;
 			}

 			if(head==NULL){
 				head=tmp2;
 				head->next=tmp1;
 				tail=tmp1;
 			}else{
 				tail->next=tmp2;
 				tmp2->next=tmp1;
 				tail=tmp1;
 			}
 		} 

 		return head;   

    }

    //4ms!
    ListNode *swapPairs_new(ListNode *head) {
    	if(head==NULL || head->next==NULL) return head;
    	ListNode* ptr0=head;
    	ListNode* ptr1=ptr0->next;

    	ListNode* outHead=ptr1;   //save out put header
    	ListNode* LastNode=NULL;  //tail
    	while(1){
    		//swap
    		ptr0->next=ptr1->next;
    		ptr1->next=ptr0;
    		
    		//connext with last tail
    		if(LastNode!=NULL){
    			LastNode->next=ptr1;
    		}

    		//update new tail
    		LastNode=ptr0;

    		//move to next pair
    		ptr0=ptr0->next;
    		if(ptr0==NULL) break;
    		ptr1=ptr0->next;
    		if(ptr1==NULL) break;
    	}

    	return outHead;
    }
};

int main(){
	ListNode* a =new ListNode(0);
	ListNode* b =new ListNode(1);
	ListNode* c =new ListNode(2);
	ListNode* d =new ListNode(3);
	ListNode* e =new ListNode(4);
	ListNode* f =new ListNode(5);

	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	//0-1-2-3-4-5
	Solution s;
	ListNode* h=s.swapPairs(a);

	ListNode* ptr=h;
	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;

	return 0;
}