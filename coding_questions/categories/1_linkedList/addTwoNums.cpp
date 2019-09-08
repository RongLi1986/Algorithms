/*
Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Explanation: 342 + 465 = 807.
*/

/*
Solution:

*/

#include "../include/header.hpp"

class Solution {
    public:
        /**
         * @param ptr of Node A and B
         * @return ptr of Node
         */
        Node* func(Node* A, Node* B) {
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

            return head->next;
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
    cout << "expect is: " << "5->1" <<endl; 
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
    cout << "expect is: " << "5->8->1" <<endl; 
    cout << "result is: ";
    printLinkedList(C);
    
    cout << "#################### tests done ###########################"<<endl;

    return 0;
}