/*
Remove Duplicates from Sorted List 
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*
use two pointers, find duplicates, remove it
*/

#include <iostream>
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
    ListNode *deleteDuplicates(ListNode *head) {
        //corner case handle
        if(head==NULL || head->next==NULL) return head;

        //two ptr to head and head->next
        ListNode* ptr1=head;
        ListNode* ptr2=head->next;


        while(ptr2!=NULL){
        	if(ptr1->val!=ptr2->val){ //no repeat
        		ptr1=ptr1->next;
        		ptr2=ptr2->next;
        	}else{ //repeat
                //if(ptr2->next!=NULL){ //delte and joint
        		ptr1->next=ptr2->next;
        		ptr2=ptr1->next;
                /*
                }else{ //ptr2 is end of linkedlist
                    ptr1->next=NULL;
                    ptr2=NULL; //delete end
                }
                */
        	}
        }

        return head;
    }
};

int main(){
    ListNode* head=new ListNode(0);
    ListNode* ptr=head;

    for(int i=0;i<5;i++){
        ListNode* temp=new ListNode(i);
        ptr->next=temp;
        ptr=ptr->next;
    }

    ListNode* ptr1=head;
    while(ptr1!=NULL){
        cout<<ptr1->val<<"-";
        ptr1=ptr1->next;
    }
    cout<<endl;

    Solution s;
    s.deleteDuplicates(head);

    ptr1=head;
    while(ptr1!=NULL){
        cout<<ptr1->val<<"-";
        ptr1=ptr1->next;
    }
    cout<<endl;
    return 0;
}