/*
Reverse Linked List II  
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
#include <iostream>
using namespace std;

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //corner case
        if(head==NULL) return head;
        
        /*
        normal case:
        head->lastTail->mptr->...nptr->nextHead->...
        
        corner case:
        lastTail is NULL or is head.
        nextHead is NULL;
        */

        ListNode* lastTail=NULL; 
        ListNode* nextHead=NULL;
        ListNode* mptr=head;
        ListNode* nptr=head;
        
        //find mptr and nptr
        int i=1;
        while(1){
            if(i==n) break;
            if(i<m){
                lastTail=mptr;
                mptr=mptr->next;
            }
            
            nptr=nptr->next;
            i++;
        }
        
        //set nextHead and lastTail
        nextHead=nptr->next;
      
        if(lastTail!=NULL)
            lastTail->next=NULL;
            
        nptr->next=NULL;
        

        //reverse: move mptr to nextHead one by one until it arrive at nptr;
        ListNode* ptr=mptr;
        while(mptr!=nptr){
            mptr=mptr->next;
            ptr->next=NULL;
            if(nextHead!=NULL)
                ptr->next=nextHead;
            
            nextHead=ptr;
                
            ptr=mptr;
        }
        
        //handle nptr
        nptr->next=nextHead;
        nextHead=nptr;
        
        //connect them
        if(lastTail!=NULL){
            lastTail->next=nextHead;
            return head;
        }else
            return nextHead;
        
    }
};


class Solution_old {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL|| head->next==NULL) return head;
        m=m-1;
        n=n-1;
        ListNode* mptr=head;
        ListNode* nptr=head;
        ListNode* subtail=NULL;
        ListNode* subhead=NULL;

        while(m!=0||n!=0){
        	if(m!=0){
        		if(m==1)
        			subtail=mptr;
        		mptr=mptr->next;
        		m--;
        	}

        	if(n!=0){
        		nptr=nptr->next;
        		n--;
        	}
        }
      	subhead=nptr->next;

      	if(subtail!=NULL)
      		subtail->next=NULL;
      	
      	nptr->next=NULL;

      	if(subtail!=NULL){
      		mptr=reverseList(mptr);
			subtail->next=mptr;
		}else{
			head=reverseList(mptr);
		}

      	ListNode* ptr=head;

      	while(ptr->next!=NULL){
      		ptr=ptr->next;
      	}

      	ptr->next=subhead;

      	return head;

    }
    
    ListNode* reverseList(ListNode* head){
    	ListNode* ptr=head;
    	ListNode* outhead=NULL;
    	ListNode* tmp=NULL;
    	while(ptr!=NULL){
    		tmp=ptr;
    		ptr=ptr->next;
    		tmp->next=outhead;
    		outhead=tmp;
    	}

    	return outhead;
    }
};


int main(){
	ListNode* a=new ListNode(0);
	ListNode* b=new ListNode(1);
	//ListNode* c=new ListNode(2);
	//ListNode* d=new ListNode(3);
	//ListNode* e=new ListNode(4);

	a->next=b;
	//b->next=c;
	//c->next=d;
	//d->next=e;
	//a->next=b;
	//a->next=b;

	Solution s;
	//ListNode* h=s.reverseList(a);
	ListNode* h=s.reverseBetween(a,1,2);

	ListNode* ptr=h;

	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;

	return 0;
}