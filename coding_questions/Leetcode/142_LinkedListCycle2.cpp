//Linked List Cycle II
/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/*
firstly, we use fast pointer and slow pointer,
if they cannot meet, return null;
else
    making another pointer to move from head (one step), and move fast ptr (one step)
    each time until they meet, the meet node is cycle's begins.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL) 
                fast=fast->next;
            else 
                return NULL;
            
            if(fast==slow){
                while(head!=fast){
                    head=head->next;
                    fast=fast->next;
                }        
                return fast;
            }

        }
        return NULL;
    }
};

int main(){
	Solution s;
	ListNode* l1=new ListNode(2);
	ListNode* ptr=l1;

	for(int i=0; i<10;i++){
		ListNode* temp2=new ListNode(1);
		ptr->next=temp2;
		ptr=ptr->next;
	}

	ptr->next=l1;

	ListNode* out=s.detectCycle(l1);

	if(out==NULL)
		cout<<"you are wrong"<<endl;
	else
		cout<<out->val<<endl;

	return 0;
}


