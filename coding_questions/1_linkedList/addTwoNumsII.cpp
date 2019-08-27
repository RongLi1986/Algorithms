/*
Add Two Numbers II
Question
You have two numbers represented by a linked list, where each node contains a single digit. 
The digits are stored in forward order, such that the 1's digit is at the head of the list. 
Write a function that adds the two numbers and returns the sum as a linked list.

Example:
Given 6->1->7 + 2->9->5. That is, 617 + 295.
Return 9->1->2. That is, 912.
*/

/*
Solution:
Add Two Numbers  +  Reverse LinkedList
*/

#include "../include/header.hpp"

class Solution {

    public:
        /**
         * @param ptr of Node A and B
         * @return ptr of Node
         */
        Node* func(Node* A, Node* B) {
            A = reverse(A);
            B = reverse(B);
            Node* head = new Node(INT_MAX);
            Node* ptr = head;
            int c = 0;
            while(A!=NULL or B!=NULL or c != 0){
                int x = (A!=NULL) ? A->val : 0;
                int y = (B!=NULL) ? B->val : 0;
                int s = x + y + c;

                c = s / 10;
                s = s % 10;
                Node* tmp = new Node(s);
                ptr->next = tmp;
                ptr = ptr->next;
                
                A = (A!=NULL) ? (A->next) : A;
                B = (B!=NULL) ? (B->next) : B;
            }

            return reverse(head->next);
        }

    private:
        Node* reverse(Node* A){
            Node* header = NULL;
            while(A!=NULL){
                Node* n = A->next;
                A->next = header;
                header = A;
                A = n;
            }

            return header;
        }
};

//test
int main(){
    Solution* s = new Solution();

    //wirte your test case in here
    cout << "##################### test begining #######################"<<endl; 
    
    cout << "test case 1" << endl;
    Node* A = new Node(7);
    Node* B = new Node(8);

    Node* C = s->func(A, B);
    cout << "expect is: " << "1->5" <<endl; 
    cout << "result is: ";
    printLinkedList(C);

    cout << endl;
    cout << "test case 2" << endl;

    A = NULL;
    B = NULL;

    C = s->func(A, B);
    cout << "expect is: " << "NULL" <<endl; 
    cout << "result is: ";
    printLinkedList(C);

    cout << endl;
    cout << "test case 3" << endl;

    A = new Node(7);
    Node* A1 = new Node(3);
    A->next = A1;

    B = new Node(8);
    Node* B1 = new Node(4);
    Node* B2 = new Node(1);
    B->next = B1;
    B1->next = B2;

    C = s->func(A, B);
    cout << "expect is: " << "9->1->4" <<endl; 
    cout << "result is: ";
    printLinkedList(C);
    cout << "#################### tests done ###########################"<<endl;

    return 0;
}