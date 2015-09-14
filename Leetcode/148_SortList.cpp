/*Sort List  
Sort a linked list in O(n log n) time using constant space complexity.
*/

/*
merge sort + rescursive
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
 
//merge sort 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int size=getLength(head);
        if(size<2) return head;
        
        head=mergeSortList(head,size);

        return head;
    }
    
    ListNode *mergeSortList(ListNode *head, int size) {
        //base case
        if(size==1) return head;
        
        //find mid node
        int mid=size/2;
        ListNode* head2=head;
        ListNode* tail1;
        while(mid!=0){
            if(mid==1) tail1=head2;
            head2=head2->next;
            mid--;
        }
        //cut list;
        tail1->next=NULL;
        
        //recursive to do two list
        head=mergeSortList(head,size/2);
        head2=mergeSortList(head2,size-size/2);
        
        //merge sub list
        head=merge(head,head2);
        
        return head;
    }

    //confirm the list length
    int getLength(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }

    
    //merge two lists
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* outhead=NULL;
        ListNode* tail=NULL;
        
        //two list exists
        while(head1!=NULL && head2!=NULL){
            if(head1->val>=head2->val){
                if(outhead==NULL){ 
                    outhead=head2;
                    tail=head2;
                    head2=head2->next;
                    tail->next=NULL;
                }else{
                    tail->next=head2;
                    tail=tail->next;
                    head2=head2->next;
                    tail->next=NULL;
                } 
            }else{
                if(outhead==NULL){ 
                    outhead=head1;
                    tail=head1;
                    head1=head1->next;
                    tail->next=NULL;
                }else{
                    tail->next=head1;
                    tail=tail->next;
                    head1=head1->next;
                    tail->next=NULL;
                }                 
            }
        }
        
        //only head1
        if(head1!=NULL){
            if(outhead==NULL){ 
                outhead=head1;
            }else{
                tail->next=head1;
            } 
        }
        
        //only head2
        if(head2!=NULL){
            if(outhead==NULL){ 
                outhead=head2;
            }else{
                tail->next=head2;
            }    
        }

        return outhead;
    }
};



class Solution_old {
public:
    ListNode *sortList(ListNode *head) {
        int size=getLength(head);
        if(size<2) return head;
        int mid=size/2;
        //find mid
        ListNode* head2=NULL;
        ListNode* ptr=head;
        while(mid>1){
        	ptr=ptr->next;
        	mid--;
        }

        //cut list
        head2=ptr;
        ptr=ptr->next;
        head2->next=NULL;
        head2=ptr;

        //recursive sort
        head=sortList(head);
        head2=sortList(head2);

        //merge
        ListNode* outhead=merge(head,head2);

        return outhead;
    }

    int getLength(ListNode* head){
    	ListNode* ptr=head;
    	int count=0;
    	while(ptr!=NULL){
    		count++;
    		ptr=ptr->next;
    	}

    	return count;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
    	ListNode* ptr1=head1;
    	ListNode* ptr2=head2;
    	ListNode* outhead=NULL;
    	ListNode* tail=NULL;
    	ListNode* tmp=NULL;
    	while(ptr1!=NULL&&ptr2!=NULL){
    		if(ptr1->val<ptr2->val){
    			if(outhead==NULL){
    				tmp=ptr1;
    				ptr1=ptr1->next;
    				tmp->next=NULL;
    				outhead=tmp;
    				tail=outhead;
    			}else{
    				tmp=ptr1;
    				ptr1=ptr1->next;
    				tmp->next=NULL;
    				tail->next=tmp;
    				tail=tmp;
    			}
    		}else{
    			if(outhead==NULL){
    				tmp=ptr2;
    				ptr2=ptr2->next;
    				tmp->next=NULL;
    				outhead=tmp;
    				tail=outhead;
    			}else{
    				tmp=ptr2;
    				ptr2=ptr2->next;
    				tmp->next=NULL;
    				tail->next=tmp;
    				tail=tmp;
    			}
    		}
    	}

    	if(ptr1!=NULL){
    		tail->next=ptr1;
    	}

    	if(ptr2!=NULL){
    		tail->next=ptr2;
    	}

    	return outhead;
    }
};

int main(){
	ListNode* a =new ListNode(10);
	ListNode* b =new ListNode(8);
	ListNode* c =new ListNode(23);
	ListNode* d =new ListNode(38);
	ListNode* e =new ListNode(17);
	ListNode* f =new ListNode(66);
	ListNode* g =new ListNode(82);
	ListNode* h =new ListNode(77);

	a->next=b;
	b->next=c;
	c->next=d;
	d->next=e;
	e->next=f;
	f->next=g;
	g->next=h;
	//10-8-23-38-17-66-82-77

	Solution s;
	//ListNode* head=s.merge(a,e);
	//cout<<s.getLength(a)<<endl;
	ListNode* head=s.sortList(a);
	ListNode* ptr=head;
	while(ptr!=NULL){
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<endl;
	

	return 0;
}