/*
Delete Node in a Linked List
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        if(node==NULL) return;
        ListNode* ptr=node;
        
        while(1){
            ptr->val=ptr->next->val;
            if(ptr->next->next==NULL){
                ptr->next=NULL;
                return;
            }
            ptr=ptr->next;
        }
        
        return;
    }
};

int main(){
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(3);
    ListNode* c=new ListNode(5);
    

    ListNode* d=new ListNode(2);
    ListNode* e=new ListNode(4);
    ListNode* f=new ListNode(6);


    ListNode* g=new ListNode(9);
    ListNode* h=new ListNode(12);
    ListNode* j=new ListNode(18);

    a->next=b;
    b->next=c;

    d->next=e;
    e->next=f;


    g->next=h;
    h->next=j;

	return 0;
}