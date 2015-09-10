/*
Copy List with Random Pointer 
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


#include <iostream>
#include <unordered_map>
using namespace std;

/*
solution:
first scan build and connect a copy list.
and use hashmap mapping each original node and copy node.

second scan handle rand ptr, use two pointers scan original and copy lists in same step.
if node in original list has rand ptr; find target from copylist by haspmap, 
and connect with copylist ptr->random;
*/

/*
 Definition for singly-linked list with a random pointer. 
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> myMap; 
        RandomListNode *outhead=NULL;
        RandomListNode *tail=NULL;
        RandomListNode *ptr=head;
        
        //copy a list, save each node into hashmap
        while(ptr!=NULL){
            RandomListNode *tmp=new RandomListNode(ptr->label);
            if(outhead==NULL){
                outhead=tmp; 
                tail=tmp;
            }else{
                tail->next=tmp;
                tail=tmp;
            }
            ptr=ptr->next;
        }
        
        //handle random ptr, scan input list, if one
        //node has random ptr, find new target node from hasmap
        //and connect with new node.
        RandomListNode *ptr2=head;
        RandomListNode *ptr3=outhead;
        RandomListNode *randPtr=NULL;
        while(ptr2!=NULL){
            if(ptr2->random!=NULL){
                randPtr=myMap[ptr2->random];
                ptr3->random=randPtr;
            }
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        
        return outhead;
    }
};

int main(){
	RandomListNode* head=new RandomListNode(0);
	RandomListNode* tmp=new RandomListNode(1);
	head->next=tmp;
	tmp->random=head;
	Solution s;
	RandomListNode* out= s.copyRandomList(head);

	RandomListNode* ptr=out;
	while(ptr!=NULL){
		cout<<ptr->label;
		if(ptr->random!=NULL)
			cout<<" random:"<<ptr->random->label<<"-";
		else
			cout<<" random: NULL -";
		ptr=ptr->next;
	}
	cout<<endl;

	return 0;
}