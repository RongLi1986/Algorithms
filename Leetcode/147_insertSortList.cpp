/*
Insertion Sort List 
Sort a linked list using insertion sort.

//pseudocode ????
for i ← 1 to length(A) - 1
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
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
    ListNode * insertionSortList(ListNode * pList) {
        ListNode* head=NULL;
        while(pList!=NULL){
            //drop a node from pList
            ListNode* insertNode=pList;
            pList=pList->next;
            insertNode->next=NULL;
            
            //insert the drop node in head
            ListNode* ptr=head;
            if(head==NULL){
                head=insertNode;
            }else if(insertNode->val<head->val){
                insertNode->next=head;
                head=insertNode;
            }else{
                int flag=0; //check it insert in loop or not
                while(ptr->next!=NULL){
                    if(ptr->val<=insertNode->val&&ptr->next->val>=insertNode->val){
                        ListNode* tmp=ptr->next;
                        ptr->next=insertNode;
                        insertNode->next=tmp;
                        flag=1;
                        break;
                    }
                    ptr=ptr->next;
                }
                if (flag==0){
                    ptr->next=insertNode;
                }
            }   

        }
        
        return head;
    }
};

class Solution_old {
public:
    ListNode * insertionSortList(ListNode * pList) {
    // zero or one element in list
        if(pList == NULL || pList->next == NULL)
            return pList;
        // head is the first element of resulting sorted list
        ListNode * head = NULL;
        while(pList != NULL) {
            ListNode * current = pList;
            pList = pList->next;
            if(head == NULL || current->val < head->val) {
                // insert into the head of the sorted list
                // or as the first element into an empty sorted list
                current->next = head;
                head = current;
            } else {
                // insert current element into proper position in non-empty sorted list
                ListNode * p = head;
                while(p != NULL) {
                    if(p->next == NULL || // last element of the sorted list
                       current->val < p->next->val) // middle of the list
                    {
                        // insert into middle of the sorted list or as the last element
                        current->next = p->next;
                        p->next = current;
                        break; // done
                    }
                    p = p->next;
                }
            }
        }
        return head;
    }
};

int main(){
    ListNode* a=new ListNode(100);
    ListNode* b=new ListNode(45);
    ListNode* c=new ListNode(67);
    ListNode* d=new ListNode(12);
    ListNode* e=new ListNode(4);
    ListNode* f=new ListNode(166);
    ListNode* g=new ListNode(200);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=NULL;


    Solution s;
    ListNode* head=s.insertionSortList(a);

    ListNode* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->val<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}
