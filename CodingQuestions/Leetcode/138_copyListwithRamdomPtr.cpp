/*
Copy List with Random Pointer 
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
solution1:
first scan build and connect a copy list.
and use hashmap mapping each original node and copy node.

second scan handle rand ptr, use two pointers scan original and copy lists in same step.
if node in original list has rand ptr; find target from copylist by haspmap, 
and connect with copylist ptr->random;

solution2:
1.create copy node, and insert after original node
2.connect random ptr;
3.split original node and random node, make them into two list
*/



/*
 Definition for singly-linked list with a random pointer. 
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


//smart way
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* ptr=head;
        
        //insert copy nodes
        while(ptr!=NULL){
            RandomListNode* tmp=new RandomListNode(ptr->label);
            RandomListNode* next=ptr->next;
            ptr->next=tmp;
            tmp->next=next;
            
            ptr=next;
        }
        
        //build random ptr
        ptr=head;
        while(ptr!=NULL){
            if(ptr->random!=NULL)
                ptr->next->random=ptr->random->next;
            
            ptr=ptr->next->next;
        }
        
        //divide this list to two
        ptr=head;
        RandomListNode* outhead=NULL;
        while(ptr!=NULL){
            RandomListNode* tmp=ptr->next;
            if(outhead==NULL) outhead=tmp;
            ptr->next=tmp->next;
            
            if(ptr->next!=NULL)
                tmp->next=ptr->next->next;
            
            ptr=ptr->next;
        }
        
        
        return outhead;
    }
};


//use hashmap and recurisve
class Solution2 {
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