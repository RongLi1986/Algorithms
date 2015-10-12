/*
Remove Linked List Elements 
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/*
use two pointer, one for current node and one for last node.
scan the list and delete target nodes.
need to consider candition that head is target node;
*/

/*
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptrPre=head; //previous one
        ListNode* ptrCur=head; //current node

        while(ptrCur!=NULL){
            if(ptrCur->val==val){  //if node is need to delete
                //head case: ptrPre and ptrCur is point head
                //it also need to update head.
                if(ptrCur==head){
                    ptrPre=ptrCur->next;
                    ptrCur=ptrPre;
                    head->next=NULL;
                    head=ptrCur;
                    continue;     //no need update ptrCur
                }else{  //normal case
                    ptrPre->next=ptrCur->next;
                    ptrCur->next=NULL;
                    ptrCur=ptrPre;
                }
            }
        

            //update ptrPre and ptrCur
            ptrPre=ptrCur;
            ptrCur=ptrCur->next;
        }
        
        return head;
    }
};


class Solution_old {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr=head;
        ListNode* LastNode=nullptr;

        while(ptr!=nullptr){
        	if(ptr->val==val){
        		//head
        		if(ptr==head){
        			ptr=head->next;
        			head->next=nullptr;
        			head=ptr;
        		}else{
        			ListNode* tmp=ptr;
        			ptr=ptr->next;
        			tmp->next=nullptr;
        			LastNode->next=ptr;
        		}

        	}else{
            	if(ptr==head){
            		LastNode=head;
            		ptr=ptr->next;
            	}else{
            		ptr=ptr->next;
            		LastNode=LastNode->next;
            	}
            }
        }

        return head;
    }
};

int main(){

	return 0;
}