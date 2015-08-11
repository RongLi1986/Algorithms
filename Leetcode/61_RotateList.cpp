/*
Rotate List 
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
#include <iostream>
using namespace std;

/*
why this question need 
k>len to make K=K%len???
*/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
 
class Solution_old {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(head==NULL||head->next==NULL) return head;
		if(k==0) return head;
		int size=0;
		ListNode* ptr=head;
		ListNode* lasttail;
		while(ptr!=0){
			if(ptr->next==NULL)
				lasttail=ptr;
			ptr=ptr->next;
			size++;

		}

		//k should not larger than size
		int count=size-k;
		if(count<=0) return head;

		/*
		for pass OJ, "(1,2) 3", output (2,1)		
		int count=size-k%size;
		if(count==size) return head;
		*/
		ptr=head;
		ListNode* uptail=NULL;
		while(count>0){
			if(count==1)
				uptail=ptr;

			ptr=ptr->next;
			count--;
		}

		uptail->next=NULL;
		lasttail->next=head;
		head=ptr;

		return head;
    }
};

/*
首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，
将整个圈连起来，接着往前跑len – k%len，从这里断开，就是要求的结果了。
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        if(k==0) return head;
        int size=1;
        ListNode* tail1=head;
        ListNode* tail2=head;
        
        //find tail and length
        while(tail1->next!=NULL){
            tail1=tail1->next;
            size++;
        }
        
        //connect tail1 to head
        tail1->next=head;
        
        //move to cut point;
        tail2=head;
        int step=1;

        size=size-k%size; //move steps
        while(size>step){
            tail2=tail2->next;
            step++;
        }
        
        //set new head and cut list
        ListNode* newHead=tail2->next;
        tail2->next=NULL;
        
        return newHead;
    }
};

int main(){
	ListNode* a=new ListNode(0);
	ListNode* b=new ListNode(1);
	ListNode* c=new ListNode(2);
	ListNode* d=new ListNode(3);
	ListNode* e=new ListNode(4);
	ListNode* f=new ListNode(5);

	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	//a->next=b;

	Solution s;
	ListNode* h=s.rotateRight(a,8);
	ListNode* ptr=h;
	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;

	return 0;
}