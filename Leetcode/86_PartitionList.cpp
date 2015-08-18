/*Partition List
Given a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the 
two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
design a small list (smaller than x) and large list (larger than x), 
put items into two list O(n). then connect small and large list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead=NULL;
        ListNode* smallTail=NULL;
        ListNode* largeHead=NULL;
        ListNode* largeTail=NULL;
        ListNode* ptr=head;
        while(ptr!=NULL){
            if(ptr->val<x){
                //put it in smallHead
                if(smallHead==NULL){
                    smallHead=ptr;
                    smallTail=ptr;
                    ptr=ptr->next;
                    smallHead->next=NULL;
                }else{
                    smallTail->next=ptr;
                    smallTail=smallTail->next;
                    ptr=ptr->next;
                    smallTail->next=NULL;
                }
            }else{ //ptr->val >=x
                //put it in largeHead
                if(largeHead==NULL){
                    largeHead=ptr;
                    largeTail=ptr;
                    ptr=ptr->next;
                    largeHead->next=NULL;
                }else{
                    largeTail->next=ptr;
                    largeTail=largeTail->next;
                    ptr=ptr->next;
                    largeTail->next=NULL;
                }
            }
        }
        
        //connect small list and large list
        //check small list's status
        if(smallHead!=NULL)
            smallTail->next=largeHead;
        else
            return largeHead;
        return smallHead;
    }
};

int main(){
	ListNode* a =new ListNode(10);
	ListNode* b =new ListNode(8);
	ListNode* c =new ListNode(23);
	ListNode* d =new ListNode(38);
	ListNode* e =new ListNode(17);
	ListNode* f =new ListNode(66);
	ListNode* g =new ListNode(82);
	ListNode* h =new ListNode(77);

	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	f->next=g;
	g->next=h;
	//10-8-23-38-17-66-82-77

	Solution s;


	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
	

	return 0;
}