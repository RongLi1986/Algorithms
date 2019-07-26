/*
Remove Duplicates from Sorted List II 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/*
basic idea: it re-construct the list, if the item is duplicate item,
then discard it. else, we link it to list.
finally, return then new list.
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
    ListNode *deleteDuplicates(ListNode *head) {
    	//corner case
        if(head==NULL||head->next==NULL)
        	return head;

        //dup flag
        int flag=1; //0 dup, 1 non dup
        
        ListNode* ptr1=head;   //pointer for traversal list
        ListNode* tail=NULL;   //for linking with tmp
        ListNode* tmp=NULL;    //
        
        //clear head
        head=NULL;

        while(ptr1!=NULL) {
        	tmp=ptr1;
        	if(ptr1->next!=NULL){ //not last one
	        	ptr1=ptr1->next;

	        	//cut the tmp(first node)
	        	tmp->next=NULL;

	        	//if two node !=, connect tmp to list
	        	if(ptr1->val!=tmp->val){
	        		if(flag==1){ //no dup, add yo list
		        		if(head==NULL){
		        			head=tmp;
		        			tail=tmp;
		        		}else{
		        			tail->next=tmp;
		        			tail=tmp;
		        		}
	        		}else{ //dup,no need add tmp to list(tmp is useless)
	        			   //,set flag back
	        			flag=1;
	        		}
	        		
	        	}else{
	        		//dup set flag no need to link tmp
	        		flag=0;
	        	}
        	}else{ //corner case last one
        		ptr1=ptr1->next; //for outloop
	        	tmp->next=NULL;
        		if(flag==1){ //no dup, add tmp to list
        			if(head==NULL){
	        			head=tmp;
	        			tail=tmp;
	        		}else{ //dup, discard it
	        			tail->next=tmp;
	        			tail=tmp;
	        		}
        		}

        	}
            
        }

        return head;
    }
};

int main(){
	ListNode* a=new ListNode(0);
	ListNode* b=new ListNode(2);
	ListNode* c=new ListNode(2);
	ListNode* d=new ListNode(2);
	ListNode* e=new ListNode(3);
	ListNode* f=new ListNode(4);

	a->next=b;
	b->next=c;
	//c->next=d;
	//d->next=e;
	//e->next=f;
	//a->next=b;

	Solution s;
	ListNode* h=s.deleteDuplicates(a);
	ListNode* ptr=h;
	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
	return 0;
}