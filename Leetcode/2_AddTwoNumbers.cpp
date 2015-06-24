/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <iostream>
#include <cstdlib>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* OutputHeader=new ListNode(0);
        ListNode* ptr3=OutputHeader;
        int carry=0;
        int sum=0;
        while(ptr1!=NULL && ptr2!=NULL){
        	sum=(ptr1->val+ptr2->val+carry)%10;
        	ptr3->val=sum;
        	ListNode* temp=new ListNode(0);
        	ptr3->next=temp;
        	ptr3=ptr3->next;
        	carry=(ptr1->val+ptr2->val+carry)/10; //update carry
        	ptr1=ptr1->next;
        	ptr2=ptr2->next;
        }

        //case for ptr2 is null
		while(ptr1!=NULL){
        	sum=(ptr1->val+carry)%10;
        	ptr3->val=sum;
        	ListNode* temp=new ListNode(0);
        	ptr3->next=temp;
        	ptr3=ptr3->next;
        	carry=(ptr1->val+carry)/10; //update carry
        	ptr1=ptr1->next;
        }        

        //case for ptr1 is null
		while(ptr2!=NULL){
        	sum=(ptr2->val+carry)%10;
        	ptr3->val=sum;
        	ListNode* temp=new ListNode(0);
        	ptr3->next=temp;
        	ptr3=ptr3->next;
        	carry=(ptr2->val+carry)/10; //update carry
        	ptr2=ptr2->next;
        }

        if(carry==1)
        	ptr3->val=1;
        else{
        	ListNode* ptr4=OutputHeader;  //kill last node(0)
        	while(ptr4->next!=ptr3){
        		ptr4++;
        	}
        	ptr4->next=NULL;
        }


        return OutputHeader; 
    }
};


int main(){
	ListNode *l1=new ListNode(5);
	ListNode *ptr1=l1;
	int i=0;
	while(i<3){
		ListNode* temp=new ListNode(i+2);
		ptr1->next=temp;
		ptr1=ptr1->next;
		i++;
	}	
	//list1 should be 5 2 3 4 
	/*
	ptr1=l1;
	while(ptr1!=NULL){
		cout<<ptr1->val<<" ";
		ptr1=ptr1->next;
	}
 	cout<<endl;
 	*/

	ListNode *l2=new ListNode(3);
	ListNode *ptr2=l2;
	int j=0;
	while(j<3){
		ListNode* temp=new ListNode(j);
		ptr2->next=temp;
		ptr2=ptr2->next;
		j++;
	}
	//list2 should be 3 0 1 2
	/*
	ptr2=l2;
	while(ptr2!=NULL){
		cout<<ptr2->val<<" ";
		ptr2=ptr2->next;
	}
 	cout<<endl;
	*/

	//I expect result is 8 2 4 6
	
	Solution s1;

	ListNode* ptr3=s1.addTwoNumbers(l1,l2);

	while(ptr3!=NULL){
		cout<<ptr3->val<<" ";
		ptr3=ptr3->next;
	}
	
	cout<<endl;
	
	return 0;
}