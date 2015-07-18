/*
Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/


/*
recursive way
1, first move to cut point (if length is small, return), keep tail 
2, cut from tail,
3, recursive to handle other part linkedlist.
3, reverse first part.
4, connect them.


iterate way
make a function, cut anbd reverse(need double pointer keep list head),
save them into vector,
finally traverse vector, connect pointer 
*/


#include <iostream>
#include <vector>
using namespace std;
/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup_recursive(ListNode *head, int k){
    	ListNode* ptr=head;
        ListNode* tail=NULL;
        int i=k;

        //move to cut point & check length
        while(i>0){
        	//cout<<i<<endl;
        	if(i==1)
        		tail=ptr;

        	if(ptr==NULL) return head;
        	ptr=ptr->next;
        	i--;
        }

        tail->next=NULL;  //cut

        //recurive
        ListNode* newhead2=reverseKGroup_recursive(ptr,k);


        //reverse first part;
        ListNode* ptr2=head;
        ListNode* newHead=NULL;
        ListNode* tmp=NULL;
        while(ptr2!=NULL){
        	tmp=ptr2;
        	ptr2=ptr2->next;
        	tmp->next=NULL;
        	if(newHead==NULL)
        		newHead=tmp;
        	else{
        		tmp->next=newHead;
        		newHead=tmp;
        	}
        }

        //connect linkedlist
        head->next=newhead2;

        return newHead;
    }


    ListNode* reverseKGroup(ListNode *head, int k){
        ListNode* outHead=NULL;
        ListNode* ptr_g=head;
        //cout<<ptr_g->val<<endl;
        vector<ListNode*> headVector;
        while(ptr_g!=NULL){
            //cout<<ptr_g->val<<endl;
            headVector.push_back(cutAndRevese(&ptr_g,k));
        }
        
        //head==NULL case
        if(headVector.empty()) return NULL;
        
        outHead=headVector[0];
        ListNode* ptr=headVector[0];
        //conncect
        for(int i=1;i<headVector.size();i++){
            
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=headVector[i];

        }

        return outHead;
    }

    ListNode* cutAndRevese(ListNode** head,int k){
        ListNode* ptr=*head;
        ListNode* tail=NULL;
        int i=k;

        //move to cut point & check length
        while(i>0){
            //cout<<i<<endl;
            if(i==1)
                tail=*head;

            if(*head==NULL) return ptr;
            *head=(*head)->next;
            i--;
        }

        tail->next=NULL;  //cut

        //reverse first part;
        ListNode* ptr2=ptr;
        ListNode* newHead=NULL;
        ListNode* tmp=NULL;
        while(ptr2!=NULL){
            tmp=ptr2;
            ptr2=ptr2->next;
            tmp->next=NULL;
            if(newHead==NULL)
                newHead=tmp;
            else{
                tmp->next=newHead;
                newHead=tmp;
            }
        }

        return newHead;
    }
};



int main(){
    
	ListNode* A=new ListNode(1);
	ListNode* B=new ListNode(2);
	ListNode* C=new ListNode(3);
	ListNode* D=new ListNode(4);
	ListNode* E=new ListNode(5);

	A->next=B;
	B->next=C;
	C->next=D;
	D->next=E;

	Solution s;
	ListNode* O=s.reverseKGroup(A,2);

	ListNode* ptr=O;

	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;



	return 0;
}