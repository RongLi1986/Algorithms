/*
Implement a Queue by linked list. Provide the following basic methods:

push_front(item). Add a new item to the front of queue.
push_back(item). Add a new item to the back of the queue.
pop_front(). Move the first item out of the queue, return it.
pop_back(). Move the last item out of the queue, return it.
Have you met this question in a real interview? Yes
Example
push_front(1)
push_back(2)
pop_back() // return 2
pop_back() // return 1
push_back(3)
push_back(4)
pop_front() // return 3
pop_front() // return 4
Tags 
*/
 

//Definition for ListNode.
/*
class ListNode {
    private:
        int val;
        ListNode* next;
    public:
        ListNode(int val) {
            this->val = val;
            this->next = null;
        }
 }
*/ 
 
class Dequeue {
private:
    ListNode* head;
    ListNode* tail;
public:    
    Dequeue() {
        // do initialize if necessary
        head=NULL;
        tail=NULL;
    }

    void push_front(int item) {
        // Write your code here
        ListNode* node=new ListNode(item);
        if(head==NULL){
            head=node;
            tail=node;
        }else{
            node->next=head;
            head=node;
        }
        return;
    }

    void push_back(int item) {
        // Write your code here
        ListNode* node=new ListNode(item);
        if(head==NULL){
            head=node;
            
        }else{
            tail->next=node;
        }
        
        tail = node;
        return;
    }

    int pop_front() {
        // Write your code here
        ListNode* node= head;
        head=head->next;
        node->next=NULL;
        if(head==NULL) 
            tail=NULL;
        return node->val;
    }

    int pop_back() {
        // Write your code here
        ListNode* node= tail;
        if(tail==head){
            head = NULL;
            tail = NULL;
        }else{
            ListNode* ptr=head;
            while(ptr->next!=tail){
                ptr=ptr->next;
            }
            ptr->next=NULL;
            tail=ptr;
        }
        
        return node->val;
    }
};
    