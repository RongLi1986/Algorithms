/*
Implement a Queue by linked list. Support the following basic methods:

enqueue(item). Put a new item in the queue.
dequeue(). Move the first item out of the queue, return it.
Have you met this question in a real interview? Yes
Example
enqueue(1)
enqueue(2)
enqueue(3)
dequeue() // return 1
enqueue(4)
dequeue() // return 2
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
  
 
class Queue {
private:
    ListNode* head;
    ListNode* tail;
public:
    Queue() {
        // do initialize if necessary
        head = NULL;
        tail = NULL;
    }

    void enqueue(int item) {
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

    int dequeue() {
        // Write your code here
        ListNode* node= head;
        head=head->next;
        node->next=NULL;
        if(head==NULL) 
            tail=NULL;
        return node->val;
    }
};
    