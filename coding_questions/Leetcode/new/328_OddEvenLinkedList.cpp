/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
 */

/*

 */



#include <iostream>
#include <vector>

using namespace std;

 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==0) return 0;
        ListNode* evenTail=0;
        ListNode* evenHead=0;
        
        ListNode* oddTail=0;
        ListNode* oddHead=0;
        
        ListNode* ptr=head;
        int count=1;
        while(ptr!=0){
            if(count%2!=0){ //odd
                if(oddHead==0){
                    oddHead=ptr;
                    oddTail=ptr;
                    ptr=ptr->next;
                    oddHead->next=0;
                    oddTail->next=0;
                }else{
                    oddTail->next=ptr;
                    oddTail=ptr;
                    ptr=ptr->next;
                    oddTail->next=0;
                }    
            }else{ //even
                if(evenHead==0){
                    evenHead=ptr;
                    evenTail=ptr;
                    ptr=ptr->next;
                    evenHead->next=0;
                    evenTail->next=0;
                }else{
                    evenTail->next=ptr;
                    evenTail=ptr;
                    ptr=ptr->next;
                    evenTail->next=0;
                }    
            }
            count++;
            //ptr=ptr->next;
        }
        
        oddTail->next=evenHead;
        
        return oddHead;
        
    }
};

int main() {

    return 0;
}